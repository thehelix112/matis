// Copyright 2001, 2002 Commonwealth of Australia
// Authors: John Wharington, David Andrews
// Defence Science Technology Organisation, Maritime Platforms Division
// CVS $RCSfile: MATIS_UniqueHandleFactory.h,v $
// CVS $Date: 2006/01/17 14:54:58 $
// CVS $Revision: 1.11 $



#ifndef MATIS_UNIQUEHANDLEFACTORY_H
#define MATIS_UNIQUEHANDLEFACTORY_H


#include "MATIS_Types.h"
#include "MATIS_Hashable.h"

namespace MATIS {
    
    template <typename valueType,
              size_t initVal> 
    
	 class UniqueHandleFactory {
        
        // actual map
        typedef std::map < handleType, 
                           valueType > mapHandleValueType;
        
	 public:
        
        //DATA
        //===============
        
        handleType lowerValue;
        
        //FUNCTIONALITY
        //===============
        
        //Default Constructor
        UniqueHandleFactory(){

            lowerValue = initVal;
            nextId = lowerValue;
            
        };
        
        //Destructor
        ~UniqueHandleFactory(){

            reset();
            
        };


        //Add a valueType given valueType
        handleType addValue(valueType aValueType){

            Hashable *aHashable = aValueType;
            ModelElement *aElement = aValueType;

            bool isNew = false;
            handleType handle = getUniqueHandle(aHashable->hash(), &isNew);
            aElement->handle = handle;
            
            if(isNew){
                setValue(handle, aValueType);
            }
            
            return handle;
            
        };


        //Remove a valueType given valueType
        handleType removeValue(valueType aValueType){
            
            handleType handle = lookupHandleByValue(&aValueType);
            removeValue(handle);

            return handle;
            
        };

        //Forward lookup
        valueType getValue(const handleType& aHandle){

            if(existsHandle(aHandle)){
                return (mapHandleValue[aHandle]);
            } else {
                LOGERR("Store Error: no value for handle: " << aHandle << "\n");
                return NULL;
            }   

        };

        //Reverse lookup
        valueType getValue(const std::string& aFullHan){
            
            handleType handle = getExistingHandle(aFullHan);
            if(handle != 0)
                return getValue(handle);
            else
                return NULL;
            
        }

        //Set the value based on the handle
        void setValue(const handleType& aHandle, valueType aValue){

            mapHandleValue[aHandle] = aValue;

        };


        //Reverse Lookup
        handleType lookupHandleByValue(valueType aValue){
            
            handleType retVal = 0;    
            typename mapHandleValueType::iterator it = mapHandleValue.begin();
            
            while (it != mapHandleValue.end()) {
                
                if ((*it).second == aValue) {
                    
                    return (*it).first;					 
                    
                }
                
                it++;
            }			 
            
            return retVal;			 

        };
        
        //Remove a handle and its object
        valueType removeValue(handleType aHandle){

            valueType retval;
            retval = getValue(aHandle);

            //record that this handle is unused
            unusedHandles.push_front(aHandle);

            //find all the identifiers for this handle
            std::pair < mapHandleUniqueStringType::const_iterator,
                mapHandleUniqueStringType::const_iterator > range 
                = mapHandleId.equal_range(aHandle);
            
            typename mapHandleUniqueStringType::const_iterator iq;

            //delete them.            
            for(iq = range.first; iq != range.second; iq++){

                mapIdHandle.erase((*iq).second);				

            }

            mapHandleId.erase(aHandle);

            //delete the value
            typename mapHandleValueType::iterator iu = mapHandleValue.find(aHandle);

            if(iu != mapHandleValue.end()){

                mapHandleValue.erase(iu);

            }

				return retval;
			
        };
        
        // should be called at destruction/resignation to reset handles.
        void reset(){

            nextId = lowerValue;
            unusedHandles.erase(unusedHandles.begin(),unusedHandles.end());
            mapHandleId.erase(mapHandleId.begin(), mapHandleId.end());
            mapHandleValue.erase(mapHandleValue.begin(), mapHandleValue.end());
            mapIdHandle.erase(mapIdHandle.begin(), mapIdHandle.end());

        };
        



        //
        void setIdToHandle(const handleType& aHandle, const std::string& aId){
			 
            //see if the handle aHandle exists.
            if(existsHandle(aHandle)){

                //if this string already maps to a DIFFERENT handle then delete it
                //otherwise, simply add ANOTHER string->handle reference.
				 
                if(findUniqueHandle(aId) > 0){
					 
                    std::pair < mapHandleUniqueStringType::iterator,
                        mapHandleUniqueStringType::iterator > p =
                        mapHandleId.equal_range(
                            mapHandleUniqueStringType::key_type(aHandle));
					 
                    mapHandleUniqueStringType::iterator it;
					 
                    bool found = false;					 
                    for(it = p.first; it != p.second; it++){

                        std::string thisId(aId.c_str(), 8);
                        std::string foundId(((*it).second).c_str(), 8);

                        if(thisId == foundId){							 

                            found = true;
                            break;						 

                        }

                    }

                    if(found){

                        //remove this one					 
                        mapHandleId.erase(it);

                    } else {						 

                        LOGMSG(2, "Error, we didn't find the existing one to remove it.\n");

                    }
					 
					 
                }
                
                //add to multi-map lookup of string from handle
                mapHandleId.insert(mapHandleUniqueStringType::value_type(aHandle, aId));
                //add to map lookup of handle from string
                mapIdHandle[aId] = aHandle;		 

            } else {
                
                LOGWRN("No such handle " << aHandle << " in the factory when trying to set reverse lookup string.\n");
                
            }
            
		 
        };

        //slightly embellished reverse lookup
        bool getHandle(const std::string &aFullHan,
                       handleType *aHandle){
            
            handleType handle = getExistingHandle(aFullHan);            
            
            if(handle != 0){
                LOGWRN("Reference made to unknown id: " << aFullhan);
                return false;
            } else {
                *aHandle = handle;
                return true;
            }
            
        }
        

        //Simplified reverse lookup assuming existing entry, returns false (0) otherwise
        handleType getExistingHandle(const std::string &aFullHan){
            
            bool isNew;
            
            handleType aHandle = getUniqueHandle(aFullHan, &isNew);
            
            if(isNew){
                return 0;
            } else {
                return aHandle;
            }
            
        }
        

        //Reverse lookup
        handleType getUniqueHandle(const std::string& aFullhan,
                                   bool *aIsNew){

            handleType retVal = findUniqueHandle(aFullhan);

            if (aIsNew != NULL) {

                *aIsNew = false;

            }

            if (retVal == 0) {

                handleType thisId = getNextHandle();
                mapIdHandle[aFullhan] = thisId;
                mapHandleId.insert(mapHandleUniqueStringType::value_type(thisId, aFullhan));
                retVal = thisId;

                if (aIsNew != NULL) {

                    *aIsNew = true;

                }

            }

            return retVal;

        };

        //check that a handle exists already
        bool existsHandle(handleType aHandle){

            mapHandleUniqueStringType::iterator it = mapHandleId.find(aHandle);

            if (it != mapHandleId.end()) {

                return true;

            } else {

                return false;

            }
        };

        //
        handleType getNextHandle(){

            handleType retVal;

            if (unusedHandles.empty()) {

                retVal = nextId;
                nextId++;

            } else {

                retVal = (unusedHandles.front());
                unusedHandles.pop_front();

            }

            return retVal;
        };      

        mapHandleValueType::iterator getIterator(){

            return it;

        };

        //return the start value
        mapHandleValueType::iterator begin(){

            return(mapHandleValue.begin());

        };

        //return the end value
        mapHandleValueType::iterator end(){

            return(mapHandleValue.end());

        };

        unsigned long size(){
            
            return(mapHandleValue.size());
            
        }
        

        //move ahead and return the current value
        /*valueType next(){

            it++;
            return (*it).second;
            
            };*/

        

    protected:

        //DATA
        //===============

        handleType nextId;
        mapUniqueStringHandleType mapIdHandle;
        mapHandleUniqueStringType mapHandleId;
        mapHandleValueType mapHandleValue;
        typename mapHandleValueType::iterator it;

    private:

        //DATA
        //===============

        queueIDHandleType unusedHandles;

        //FUNCTIONALITY
        //===============

        handleType findUniqueHandle(const std::string& aFullhan){

            typename mapUniqueStringHandleType::iterator it = mapIdHandle.find(aFullhan);

            if (it != mapIdHandle.end()) {

                return ((*it).second);

            } else {

                return 0;

            }

        };

    };

}

#endif                          // MATIS_UNIQUEHANDLEFACTORY_H
