#ifndef LINKQUALITYEVENT_H_
#define LINKQUALITYEVENT_H_

namespace SSI
{
	/**
	* An instance of this type is provided when a new link quality value is provided.
	*/
	class LinkQualityEvent
	{
	public:
		/**
		* Initializes a new instance of the LinkQualityEvent class.
		* @param videoStreamQuality.
		*/
		LinkQualityEvent(int quality);
		virtual ~LinkQualityEvent();

		/**
		* Gets the link quality.
		* @return The link quality or null if an error occurred.
		*/
		const int getQuality() const;
	private:
		LinkQualityEvent();
		LinkQualityEvent(const LinkQualityEvent& copyMe);
		LinkQualityEvent& operator=(const LinkQualityEvent&);
		int _quality;
	};
}
#endif