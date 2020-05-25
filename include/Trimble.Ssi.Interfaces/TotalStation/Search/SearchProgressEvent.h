#ifndef SEARCHPROGRESSEVENT_H_
#define SEARCHPROGRESSEVENT_H_

namespace SSI
{
	/**
	* Provides data for the <see cref="ISsiSearch.ProgressChanged"/> event.
	* <seealso cref="ISsiSearch.ProgressChanged"/>
	* <seealso cref="ISsiSearch"/>
	*/
	class SearchProgressEvent
	{
	public:
		/**
		* Initializes a new instance of the <see cref="SearchProgressEvent"/> class.
		* @param percentage The percentage between 0 and 100.
		*/
		SearchProgressEvent(unsigned char percentage);
		virtual ~SearchProgressEvent();

		/**
		* Gets the current progress in percent.
		* @return The current progress in percent.
		*/
		unsigned char getSearchProgress() const;
	private:
		SearchProgressEvent();
		SearchProgressEvent(const SearchProgressEvent& copyMe);
		unsigned char _percentage;
	};
}
#endif