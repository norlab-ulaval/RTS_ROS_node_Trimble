#ifndef LOGFILESTORAGETYPE_H_
#define LOGFILESTORAGETYPE_H_

namespace SSI
{
    /**
     * Defines constant log file storage type objects
     */
    enum LogFileStorageType
    {
        /**
         * Log file at receiver's internal storage
         */
        LFST_Internal,

        /**
         * Log file at receiver's external storage. Ex. SDCard or USB stick.
         */
        LFST_External,

        /**
         * Log file at controller's local storage
         */
        LFST_Controller
    };
}
#endif
