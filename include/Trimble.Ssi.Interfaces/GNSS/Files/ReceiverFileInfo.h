#ifndef RECEIVERFILEINFO_H_
#define RECEIVERFILEINFO_H_

#include <string>

namespace SSI
{
	/**
	* Represents a Gnss receiver log file instance.
	*/
	class ReceiverFileInfo
	{
	public:
		ReceiverFileInfo(std::string fileName, unsigned int size, long long created);

		/*
		* Initializes a new instance of the ReceiverFileInfo
		* @param ReceiverFileInfo&
		*/
		ReceiverFileInfo(const ReceiverFileInfo& assignMe);

		/**
		* Gets the name of the file.
		* @return The name of the file.
		*/
		std::string getFileName();

		/**
		* Sets the name of the file.
		* @param The name of the file.
		*/
		void setFileName(std::string fileName);

		/**
		* Gets the created date.
		* @return The created date.
		*/
		long long getCreated();

		/**
		* Sets the created date.
		* @param The created date.
		*/
		void setCreated(long long created);

		/**
		* Gets the size.
		* @return The size.
		*/
		unsigned int getSize();

		/**
		* Sets the size.
		* @param The size.
		*/
		void setSize(unsigned int size);

		ReceiverFileInfo& clone();
		ReceiverFileInfo& operator=(const ReceiverFileInfo& assignMe);
	private:
		std::string _fileName;
		long long _created;
		unsigned int _size;
	};
}
#endif