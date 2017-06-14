// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews, Peter Beckwith, Nicholas Hynes
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_MessageLogger.h,v $
// CVS $Date: 2005/11/11 04:51:14 $
// CVS $Revision: 1.1.1.1 $


#ifndef MESSAGELOGGER_H
#define MESSAGELOGGER_H 1

#include <string>
#include <iostream>
#include <fstream>

namespace MATIS {

    class MessageLogger {
        
    protected:
        
        MessageLogger();
        int filterLevel;
        bool displayContext;
        
    public:
        
        static MessageLogger* getLogger();
        void write(int aLevel, 
                   std::string aMessage, 
                   std::string aFile,
                   int aLine, 
                   std::string aFunction);
        bool willWrite(int aLevel);
        bool willContext();
        
    private:
        
        /**
         * @link
         * @shapeType PatternLink
         * @pattern Singleton
         * @supplierRole Singleton factory 
         */
        /*# MessageLogger _messageLogger; */
        static MessageLogger* loggerInstance;
    };

} // namespace

#endif //MESSAGELOGGER_H
