#ifndef MOUNTPOINTLIST_H_
#define MOUNTPOINTLIST_H_

#include <vector>
#include <string>

namespace SSI
{
	/*
	* Provides data for the  ReferenceStation Update event
	*/
	class MountPointList
	{
	public:
		/*
		* Initializes a new instance of the MountPointList
		* @param mountPointList mount point list
		*/
		MountPointList(const std::vector<std::string>& mountPointList);
		MountPointList();
		MountPointList(const MountPointList& copyMe);
		MountPointList& operator=(const MountPointList&);

		/*
		* Gets the list of mount points
		* @return mount point list
		*/
		const std::vector<std::string>& getList() const;
	private:
		std::vector<std::string> _mountPointList;
	};
}
#endif