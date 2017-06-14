        //Static Convenience Functionality
        static bool getEntry(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMEntryStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMENTRY, id))) > 0);      
        };
        static bool getExit(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMExitStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMEXIT, id))) > 0);
        };
        static bool getLAETerm(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMLAETermStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMLAETERM, id))) > 0);
        };
        static bool getLAE(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMLAEStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMLAE, id))) > 0);;    
        };
        static bool getMethodCall(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMMethodCallStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMMETHODCALL, id))) > 0);
        };
        static bool getPropertySet(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMPropertySetStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMPROPERTYSET, id))) > 0);
        };
        static bool getLAEInteraction(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMLAEInteractionStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMLAEINTERACTION, id))) > 0);
        };

        static bool getException(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMExceptionStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMEXCEPTION, id))) > 0);
        };
        static bool getUnordered(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMUnorderedStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMUNORDERED, id))) > 0);
        };
        static bool getGroup(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMGroupStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMGROUP, id))) > 0);
        };
        static bool getProcess(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMProcessStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMPROCESS, id))) > 0);
        };
        static bool getHost(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMHostStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMHOST, id))) > 0);
        };
        static bool getFile(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMFileStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMFILE, id))) > 0);
        };
        static bool getMethod(std::string id, handleType *handle){
            return ((*handle = Model::LEAPBMMethodStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LEAPBMMETHOD, id))) > 0);
        };


        static bool getEntry(std::string id, void *object){
            handleType handle;
            if(getEntry(id, &handle)){
                (LEAPBMEntry*)object = Model::LEAPBMEntryStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getExit(std::string id, void *object){
            handleType handle;
            if(getExit(id, &handle)){
                (LEAPBMExit*)object = Model::LEAPBMExitStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getLAETerm(std::string id, void *object){
            handleType handle;
            if(getLAETerm(id, &handle)){
                (LEAPBMLAETerm*)object = Model::LEAPBMLAETermStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getLAE(std::string id, void *object){
            handleType handle;
            if(getLAE(id, &handle)){
                (LEAPBMLAE*)object = Model::LEAPBMLAEStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getMethodCall(std::string id, void *object){
            handleType handle;
            if(getMethodCall(id, &handle)){
                (LEAPBMMethodCall*)object = Model::LEAPBMMethodCallStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getPropertySet(std::string id, void *object){
            handleType handle;
            if(getPropertySet(id, &handle)){
                (LEAPBMPropertySet*)object = Model::LEAPBMPropertySetStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getLAEInteraction(std::string id, void *object){
            handleType handle;
            if(getLAEInteraction(id, &handle)){
                (LEAPBMLAEInteraction*)object = Model::LEAPBMLAEInteractionStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getException(std::string id, void *object){
            handleType handle;
            if(getException(id, &handle)){
                (LEAPBMException*)object = Model::LEAPBMExceptionStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getUnordered(std::string id, void *object){
            handleType handle;
            if(getUnordered(id, &handle)){
                (LEAPBMUnordered*)object = Model::LEAPBMUnorderedStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getGroup(std::string id, void *object){
            handleType handle;
            if(getGroup(id, &handle)){
                (LEAPBMGroup*)object = Model::LEAPBMGroupStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getProcess(std::string id, void *object){
            handleType handle;
            if(getProcess(id, &handle)){
                (LEAPBMProcess*)object = Model::LEAPBMProcessStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getHost(std::string id, void *object){
            handleType handle;
            if(getHost(id, &handle)){
                (LEAPBMHost*)object = Model::LEAPBMHostStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getFile(std::string id, void *object){
            handleType handle;
            if(getFile(id, &handle)){
                (LEAPBMFile*)object = Model::LEAPBMFileStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getMethod(std::string id, void *object){
            handleType handle;
            if(getMethod(id, &handle)){
                (LEAPBMMethod*)object = Model::LEAPBMMethodStore.getValue(handle);
                return true;
            } else
                return false;
        };

        //pathways are an exception as they are idless so we need to be provided
        //with their destination and destinationtype
        static bool getPathway(handleType destination, 
                               pathwayDestinationTypeType destinationType, 
                               handleType *handle){

            char buffer[8];
            *(int*)(&buffer) = destination;
            *(int*)(&buffer[4]) = destinationType;
            
            std::string fullhan = Hashable::hashObject(OBJECT_LEAPBMPATHWAY, std::string(buffer, 8));

            return ((*handle = Model::LEAPBMPathwayStore.getExistingHandle(fullhan)) > 0);
        };

        static bool getPathway(handleType destination, 
                               pathwayDestinationTypeType destinationType, 
                               void *object){
            handleType handle;
            if(getPathway(destination, destinationType, &handle)){
                (LEAPBMPathway*)object = Model::LEAPBMPathwayStore.getValue(handle);
                return true;
            } else
                return false;
        };

        static bool isPropertyInAction(LAEProperty* aLAEProperty, Action *aAction){
    
            //check if the properties action_storage meta exists.
            //  for action_handle storage category check that the specific one exists
            handleValuePairSetType::iterator it;
            
            switch(aLAEProperty->actionStorageCategory){
                
            case STORAGE_HS:
                return(aAction->hs.size() > 0);
                break;
            case STORAGE_HS2:
                return(aAction->hs2.size() > 0);
                break;
            case STORAGE_HVPS:
                return(aAction->hvps.size() > 0);
                break;
            case STORAGE_HVPS2:
                return(aAction->hvps.size() > 0);
                break;
            case STORAGE_RS:
                return(aAction->rs.size() > 0);
                break;            
            case STORAGE_ACTIONHANDLE:
                it = aAction->metadata.find(
                    Action_RTI_13NG::stringToActionMetaHandle(aLAEProperty->actionStorage));
                return(it != aAction->metadata.end());
                break;
                
            default:
                return false;
                break;
                
            }
            
            //OR
            
            /*go through sources,
              
            get the apimethods associated with
            apiparameter sources
            
            check if the context of this apimethod matches the action.
            
            if it does then the property should be in the action?*/
            
            return false;            
            
        };

