#include "SsiInstrument.h"
#include "SsiCallbacks.h"

#include "DriverManagerInstance.h"
#include "SsiException.h"
#include "Connection/IConnectionParameterExternalSettings.h"
#include "Connection/IConnectionParameterTCPIPSettings.h"
#include "Connection/IConnectionParameterUSBSettings.h"
#include "SensorProperties/ISsiSensorProperties.h"
#include "Power/ISsiPower.h"
#include "Observations/ISsiMeasurement.h"
#include "Observations/ISsiTracking.h"
#include "IdleAngles/ISsiIdleAngles.h"
#include "Face/ISsiFace.h"
#include "Targets/ISsiTargets.h"
#include "Targets/IDirectReflexTarget.h"
#include "Targets/IDirectReflexAdvancedTarget.h"
#include "Targets/IPrismTarget.h"
#include "Targets/IPrismAdvancedTarget.h"
#include "Targets/ITrimbleMultiTrackTarget.h"
#include "Tilt/ISsiTilt.h"
#include "TrackLight/ISsiTrackLight.h"
#include "StatusLight/ISsiStatusLight.h"
#include "Servo/ISsiServo.h"
#include "Servo/ITurnToParameterHorizontalAngle.h"
#include "Servo/ITurnToParameterVerticalAngle.h"
#include "Servo/ITurnToFeatureSpeed.h"
#include "Servo/TurnToSettings.h"

#include "ISsiVision.h"
#include "Camera/ICamera.h"
#include "Camera/ICameraFeatureImage.h"
#include "Camera/ICameraFeatureVideo.h"
#include "CaptureParameter/ICaptureParameterOpticalZoom.h"

#include "TCPCommunicator.h"
#include "USBCommunicator.h"

#include <ctime>
#include <cstring> 
#include <iostream>
#include <stdexcept>

extern int ssi_output(const char* fmt, ...);

SsiInstrument::SsiInstrument(void) : 
_DriverManager(getDriverManagerInstance()),
_pDriver(0),
_pSensor(0),
_pCallback(0)
{

}

SsiInstrument::~SsiInstrument(void)
{
	FreeDriver();
}

int SsiInstrument::FreeDriver()
{
	if(_pCallback)
	{
		DisConnect();
	}
	if(_pSensor)
	{
		_DriverManager.freeSensor(_pDriver, _pSensor);
		_pSensor = 0;
	}
	if(_pDriver)
	{
		_DriverManager.freeDriver(_pDriver);
		_pDriver = 0;
	}
	return 0;
}

SsiInstrument &SsiInstrument::GetInstrument()
{
	static SsiInstrument inst;
	return inst;
}

int SsiInstrument::LoadDriver(const char* sDriver)
{
	FreeDriver();

	std::string fullpath;
	fullpath = fullpath + "Trimble.Ssi.Driver.CarpoBased.Driver." + sDriver;

	try
	{
		_pDriver = &_DriverManager.loadDriver(fullpath, 0);
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;
}

std::string SsiInstrument::PrintDriverInformation(){
    std::string info_text;

    if(_pDriver){
        info_text = "Id: " + _pDriver->getDriverInformation().getUniqueId() + 
                    ", Name: " + _pDriver->getDriverInformation().getDisplayName() +
                    ", Version: " + _pDriver->getDriverInformation().getVersion() + 
                    ", Copyright: " + _pDriver->getDriverInformation().getCopyright() +
                    ", Licence: " + _pDriver->getDriverInformation().getLicenseName();
    }else{
        info_text = "No driver loaded";
    }

    return info_text;
}

int SsiInstrument::Connect(const char* sType, const char* sPort)
{
	if(!_pDriver)
		return -1;

	try
	{
		if(!_pSensor)
			_pSensor = &_pDriver->createSensor();
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}

	if(sType == 0)
	{
		std::vector<SSI::ConnectionType> list = _pSensor->listSupportedConnectionTypes();
		if(list[0] == SSI::CT_USB)
		{
			sType = "usb";
		}
		else if (list[0] == SSI::CT_TCPIP)
		{
			sType = "tcp";
		}
		else if(list[0] == SSI::CT_INTERNAL)
		{
			sType = "int";
		}
		else
		{
			printf("%s\n", "Not supported type");
			return -1;
		}
	}

	SSI::ConnectionSettings *settings = 0;
	int err = 0;
	try
	{
		if(strcmp("usb", sType) == 0)
		{
			SSI::IConnectionParameterUSBSettings& param = dynamic_cast<SSI::IConnectionParameterUSBSettings&>(_pSensor->createConnectionParameter(SSI::CPT_USBSettings));
			int vid = param.getVendorId();
			int pid = param.getProductId();

			Common::USBCommunicator* usbc = new Common::USBCommunicator(vid, pid);
			param.setCommunicator(*usbc);

			std::vector<SSI::IConnectionParameter*> params;
			params.push_back(&param);

			settings = new SSI::ConnectionSettings(SSI::CT_USB, params);
		}
		else if(strcmp("int", sType) == 0)
		{
			settings = new SSI::ConnectionSettings(SSI::CT_INTERNAL);
		}
		else if(strcmp("tcp", sType) == 0)
		{
			char* port = (char*)strchr(sPort, ':');
			if(port)
			{
				*port = 0;
				port++;
			}
			SSI::IConnectionParameterTCPIPSettings& param = (SSI::IConnectionParameterTCPIPSettings&)_pSensor->createConnectionParameter(SSI::CPT_TCPIPSettings);
			int nPort = param.getTCPIPPort();
			if(port)
			{
				nPort = atoi(port);
			}

			Common::TCPCommunicator* tcpc = new Common::TCPCommunicator(std::string(sPort), nPort);
			param.setCommunicator(*tcpc);

			std::vector<SSI::IConnectionParameter*> params;
			params.push_back(&param);
			settings = new SSI::ConnectionSettings(SSI::CT_TCPIP, params);
		}
		else
		{
			throw std::runtime_error("ConnectionSettings is not supported");
		}
		_pSensor->connect(*settings);
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		err = e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		err = -1;
	}
	delete settings;

	if(err == 0)
		_pCallback = new SsiCallbacks();
	return err;
}

int SsiInstrument::DisConnect()
{
	if(!_pSensor)
		return -1;

	try
	{
		std::vector<SSI::IConnectionParameter*> params = _pSensor->getConnectionSettings().getConnectionParameters();
		_pSensor->disconnect();
		for (std::vector<SSI::IConnectionParameter*>::iterator it = params.begin(); it != params.end(); it++)
		{
			SSI::IConnectionParameterExternalSettings* ext = dynamic_cast<SSI::IConnectionParameterExternalSettings*>(*it);
			if (ext)
			{
				delete &ext->getCommunicator();
			}

			delete (*it);
		}
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}

	delete _pCallback;
	_pCallback = 0;

	return 0;
}

int SsiInstrument::GetProperty()
{
	if(!_pSensor)
		return -1;

	SSI::ISsiSensorProperties* sensorprop = (SSI::ISsiSensorProperties*)_pSensor->getInterface(SSI::IT_SsiSensorProperties);
	if(!sensorprop)
		return -1;

	try
	{
		SSI::ISensorProperty* prop = sensorprop->getProperty(SSI::SPT_Model);
		if(prop) _pCallback->OnSensorProperty(*prop, SSI::SPT_Model);

		prop = sensorprop->getProperty(SSI::SPT_Name);
		if(prop) _pCallback->OnSensorProperty(*prop, SSI::SPT_Name);

		prop = sensorprop->getProperty(SSI::SPT_SerialNumber);
		if(prop) _pCallback->OnSensorProperty(*prop, SSI::SPT_SerialNumber);

		prop = sensorprop->getProperty(SSI::SPT_Firmware);
		if(prop) _pCallback->OnSensorProperty(*prop, SSI::SPT_Firmware);
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}

	return 0;
}

int SsiInstrument::Power(int option)
{
	if(!_pSensor)
		return -1;

	SSI::ISsiPower* theInterface = (SSI::ISsiPower*)_pSensor->getInterface(SSI::IT_SsiPower);
	if(!theInterface)
		return -1;
	try
	{

		if(option == 0)
		{
			_pCallback->OnPower(theInterface->getCurrentPowersource());
		}
		else if(option == 1)
		{
			theInterface->addCurrentPowerSourceChangedListener(*_pCallback);
		}
		else
		{
			theInterface->removeCurrentPowerSourceChangedListener(*_pCallback);
		}
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;
}

int SsiInstrument::ChangeFace()
{
	if(!_pSensor)
		return -1;

	SSI::ISsiFace* face = (SSI::ISsiFace*)_pSensor->getInterface(SSI::IT_SsiFace);
	if(!face)
		return -1;

	try
	{
		face->changeFace();
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}

	return 0;
}

int SsiInstrument::DoMeasure(bool bAngleonly)
{
	if(!_pSensor)
		return -1;

	SSI::ISsiMeasurement* meas = (SSI::ISsiMeasurement*)_pSensor->getInterface(SSI::IT_SsiMeasurement);
	if(!meas)
		return -1;

	SSI::MeasurementSettings settings(bAngleonly ? SSI::MT_Angles : SSI::MT_AnglesAndDistance);
	try
	{
		SSI::TSObservationContainer tsobs = meas->measure(settings);
		_pCallback->OnMeasure(tsobs);
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}

	return 0;
}

int SsiInstrument::Tracking(bool bStart, int param)
{
	return Tracking(bStart, _pCallback ,param);
}

int SsiInstrument::Tracking(bool bStart, SSI::ITrackingObservationsListener* listener, int param )
{
	if(!_pSensor)
		return -1;

	SSI::ISsiTracking* theInterface = (SSI::ISsiTracking*)_pSensor->getInterface(SSI::IT_SsiTracking);
	if(!theInterface)
		return -1;
	try
	{
		if(bStart)
		{
			theInterface->addTrackingObservationsListener(*listener);
			SSI::TrackingMode speed = SSI::TM_Normal;
			if (param == 1)
			{
				speed = SSI::TM_TenHz;
			}
			else if (param == 2)
			{
				speed = SSI::TM_TwentyHz;
			}
			theInterface->startTracking(speed);
		}
		else
		{
			theInterface->stopTracking();
			theInterface->removeTrackingObservationsListener(*listener);
		}
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;

}

int SsiInstrument::IdleAngles(int option)
{
	if(!_pSensor)
		return -1;

	SSI::ISsiIdleAngles* theInterface = (SSI::ISsiIdleAngles*)_pSensor->getInterface(SSI::IT_SsiIdleAngles);
	if(!theInterface)
		return -1;
	try
	{

		if(option == 0)
		{
			_pCallback->OnIdleAngles(theInterface->getIdleAngles());
		}
		else if(option == 1)
		{
			theInterface->addIdleAnglesChangedListener(*_pCallback);
			theInterface->startStreamingIdleAngles();
		}
		else
		{
			theInterface->stopStreamingIdleAngles();
			theInterface->removeIdleAnglesChangedListener(*_pCallback);
		}
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;
}

int SsiInstrument::Target(int mode, int target_id)
{
	if(!_pSensor)
		return -1;

	SSI::ISsiTargets* theInterface = (SSI::ISsiTargets*)_pSensor->getInterface(SSI::IT_SsiTargets);
	if(!theInterface)
		return -1;

	try
	{
		if(mode == MODE_DR)
		{
			SSI::IDirectReflexTarget* target = (SSI::IDirectReflexTarget*)theInterface->createTarget(SSI::TT_DirectReflex);
			target->setLaserPointerActive(false);
			theInterface->setTarget(*target);
            delete target;
		}
		else if(mode == MODE_DR_LASER)
		{
			SSI::IDirectReflexTarget* target = (SSI::IDirectReflexTarget*)theInterface->createTarget(SSI::TT_DirectReflex);
			target->setLaserPointerActive(true);
			theInterface->setTarget(*target);
            delete target;
		}
        else if(mode == MODE_DR_WEAK)
		{
			SSI::IDirectReflexAdvancedTarget* target = (SSI::IDirectReflexAdvancedTarget*)theInterface->createTarget(SSI::TT_DirectReflexAdvanced);
			target->setLaserPointerActive(false);
            target->useWeakSignal(true);
			theInterface->setTarget(*target);
            delete target;
		}
		else if(mode == MODE_AUTOLOCK)
		{
			SSI::IPrismAdvancedTarget* target = (SSI::IPrismAdvancedTarget*)theInterface->createTarget(SSI::TT_PrismAdvanced);
			target->setWorkingMode(SSI::WM_Autolock);
			theInterface->setTarget(*target);
            delete target;
		}
		else if(mode == MODE_MULTITRACK)
		{
			SSI::ITrimbleMultiTrackTarget* target = (SSI::ITrimbleMultiTrackTarget*)theInterface->createTarget(SSI::TT_TrimbleMultiTrack);
			target->setTargetId(target_id);
			target->setWorkingMode(SSI::WM_Autolock);
			theInterface->setTarget(*target);
			delete target;
		}
		else
		{
			SSI::IPrismTarget* target = (SSI::IPrismAdvancedTarget*)theInterface->createTarget(SSI::TT_Prism);
			theInterface->setTarget(*target);
            delete target;
		}
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;
}

int SsiInstrument::Video(bool bStart, VideoStreamingListener& video_streaming_listener)
{
	if(!_pSensor)
		return -1;

	SSI::ISsiVision* theInterface = (SSI::ISsiVision*)_pSensor->getInterface(SSI::IT_SsiVision);
	if(!theInterface)
		return -1;
	try
	{

		if(bStart)
		{
			std::vector<SSI::CameraInformation> list = theInterface->listAvailableCameras();

			SSI::ICamera* camera = theInterface->getCamera(list[0]);

			SSI::ICameraFeatureVideo* video = (SSI::ICameraFeatureVideo*)camera->getFeature(SSI::CFT_Video);

			video->addVideoStreamingUpdateListener(video_streaming_listener);
			video->addStreamingStateChangedListener(video_streaming_listener);

			std::vector<SSI::ICaptureParameter*> v;
			video->startVideo(v);
		}
		else
		{
			std::vector<SSI::CameraInformation> list = theInterface->listAvailableCameras();

			SSI::ICamera* camera = theInterface->getCamera(list[0]);

			SSI::ICameraFeatureVideo* video = (SSI::ICameraFeatureVideo*)camera->getFeature(SSI::CFT_Video);

			video->stopVideo();

			video->removeVideoStreamingUpdateListener(video_streaming_listener);
			video->removeStreamingStateChangedListener(video_streaming_listener);
		}
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;

}

int SsiInstrument::Video(bool bStart)
{
	if(!_pSensor)
		return -1;

	SSI::ISsiVision* theInterface = (SSI::ISsiVision*)_pSensor->getInterface(SSI::IT_SsiVision);
	if(!theInterface)
		return -1;
	try
	{

		if(bStart)
		{
			std::vector<SSI::CameraInformation> list = theInterface->listAvailableCameras();

			SSI::ICamera* camera = theInterface->getCamera(list[0]);

			SSI::ICameraFeatureVideo* video = (SSI::ICameraFeatureVideo*)camera->getFeature(SSI::CFT_Video);

			video->addVideoStreamingUpdateListener(*_pCallback);
			video->addStreamingStateChangedListener(*_pCallback);

			std::vector<SSI::ICaptureParameter*> v;
			video->startVideo(v);
		}
		else
		{
			std::vector<SSI::CameraInformation> list = theInterface->listAvailableCameras();

			SSI::ICamera* camera = theInterface->getCamera(list[0]);

			SSI::ICameraFeatureVideo* video = (SSI::ICameraFeatureVideo*)camera->getFeature(SSI::CFT_Video);

			video->stopVideo();

			video->removeVideoStreamingUpdateListener(*_pCallback);
			video->removeStreamingStateChangedListener(*_pCallback);
		}
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;

}

int SsiInstrument::Image()
{
	if(!_pSensor)
		return -1;

	SSI::ISsiVision* theInterface = (SSI::ISsiVision*)_pSensor->getInterface(SSI::IT_SsiVision);
	if(!theInterface)
		return -1;
	try
	{
		std::vector<SSI::CameraInformation> list = theInterface->listAvailableCameras();

		SSI::ICamera* camera = theInterface->getCamera(list[0]);

        SSI::ICameraFeatureImage* image = (SSI::ICameraFeatureImage*)camera->getFeature(SSI::CFT_Image);

		SSI::IImageCapture* img = (SSI::IImageCapture*)image->captureImage();
		_pCallback->OnImage(*img);

		delete img;
	}
	catch (SSI::SsiException& e)
	{
		printf("%s\n", e.what());
		return e.getErrorCode();
	}
	catch (std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;

}

int SsiInstrument::Elevel(bool bStart)
{
    if(!_pSensor)
        return -1;

    SSI::ISsiTilt* theInterface = (SSI::ISsiTilt*)_pSensor->getInterface(SSI::IT_SsiTilt);
    if(!theInterface)
        return -1;
    try
    {

        if(bStart)
        {
            theInterface->addTiltChangedListener(*_pCallback);
            theInterface->addTiltStateChangedListener(*_pCallback);
            theInterface->startStreamingTiltValues();
        }
        else
        {
            theInterface->stopStreamingTiltValues();
            theInterface->removeTiltChangedListener(*_pCallback);
            theInterface->removeTiltStateChangedListener(*_pCallback);
        }
    }
    catch (SSI::SsiException& e)
    {
        printf("%s\n", e.what());
        return e.getErrorCode();
    }
    catch (std::exception& e)
    {
        printf("%s\n", e.what());
        return -1;
    }
    return 0;

}

int SsiInstrument::setServosAnglesSynchronous(double HA, double VA)
{
	if(!_pSensor)
		return -1;
	
	SSI::ISsiServo* servo_interface = (SSI::ISsiServo*)_pSensor->getInterface(SSI::IT_SsiServo);
	if(!servo_interface)
		return -1;

	try
    {
		SSI::ITurnToParameterHorizontalAngle* turn_to_parameter_HA = (SSI::ITurnToParameterHorizontalAngle*)servo_interface->createTurnToParameter(SSI::TurnToParameterType::TTPT_HorizontalAngle);
		SSI::ITurnToParameterVerticalAngle* turn_to_parameter_VA = (SSI::ITurnToParameterVerticalAngle*)servo_interface->createTurnToParameter(SSI::TurnToParameterType::TTPT_VerticalAngle);
		turn_to_parameter_HA->setHorizontalAngle(HA);
		turn_to_parameter_VA->setVerticalAngle(VA);

		SSI::ITurnToFeatureSpeed* turn_to_feature_speed = (SSI::ITurnToFeatureSpeed*)servo_interface->createTurnToFeature(SSI::TurnToFeatureType::TTFT_Speed);
		turn_to_feature_speed->setSpeed(turn_to_feature_speed->getMaximumSpeed());
		std::vector<SSI::ITurnToFeature*> turn_to_features;
		turn_to_features.push_back(turn_to_feature_speed);

		SSI::TurnToSettings turn_to_settings_HA(*turn_to_parameter_HA, turn_to_features);
		SSI::TurnToSettings turn_to_settings_VA(*turn_to_parameter_VA, turn_to_features);

		servo_interface->turnTo(turn_to_settings_HA);
		std::cout << "Horizontal angle set" << std::endl;
		servo_interface->turnTo(turn_to_settings_VA);
		std::cout << "Vertical angle set" << std::endl;
    }
    catch (SSI::SsiException& e)
    {
        printf("%s\n", e.what());
        return e.getErrorCode();
    }
    catch (std::exception& e)
    {
        printf("%s\n", e.what());
        return -1;
    }

	return 0;
}
