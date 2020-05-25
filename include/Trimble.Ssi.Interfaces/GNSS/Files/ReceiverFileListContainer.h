#ifndef RECEIVERFILELISTCONTAINER_H_
#define RECEIVERFILELISTCONTAINER_H_

#include "ReceiverFileInfo.h"
#include <vector>

namespace SSI
{
	/**
	* Provides access to logging information that were generated during data logging.
	* @see ISurveyLogSession
	*/
	class ReceiverFileListContainer
	{
	public:
		/**
		* constructor.
		* @param std::vector<ReceiverFileInfo*> the fileLists
		*/
		ReceiverFileListContainer(std::vector<ReceiverFileInfo*>& fileLists,long long availableMemory);
		ReceiverFileListContainer();
		virtual ~ReceiverFileListContainer();

		/**
		* get the fileLists.
		* @return the fileLists
		*/
		std::vector<ReceiverFileInfo*> getList() const;

		ReceiverFileListContainer(const ReceiverFileListContainer& copyMe);

		ReceiverFileListContainer& operator=(const ReceiverFileListContainer&);

		long long getAvailableMemory();

		void addReceiverFileInfo(ReceiverFileInfo* receiverFileInfo);

		void clearReceiverFileList();

		void setAvailableMemory(long long availableMemory);
	protected:
		std::vector<ReceiverFileInfo*> _fileLists; /** fileList list */
		long long _availableMemory;
	};
}
#endif