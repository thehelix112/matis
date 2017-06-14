        //Static Functionality
        static bool getPolicy(std::string id, handleType *handle){
            return ((*handle = Model::LAEPolicyStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEPOLICY, id))) > 0);      
        };
        static bool getClass(std::string id, handleType *handle){
            return ((*handle = Model::LAEClassStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAECLASS, id))) > 0);
        };
        static bool getTrigger(std::string id, handleType *handle){
            return ((*handle = Model::LAETriggerStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAETRIGGER, id))) > 0);
        };
        static bool getRequirement(std::string id, handleType *handle){
            return ((*handle = Model::LAERequirementStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEREQUIREMENT, id))) > 0);;    
        };
        static bool getChecker(std::string id, handleType *handle){
            return ((*handle = Model::LAECheckerStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAECHECKER, id))) > 0);
        };
        static bool getFunction(std::string id, handleType *handle){
            return ((*handle = Model::LAEFunctionStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEFUNCTION, id))) > 0);
        };
        static bool getPropertyReference(std::string id, handleType *handle){
            return ((*handle = Model::LAEPropertyReferenceStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEPROPERTYREFERENCE, id))) > 0);
        };
        static bool getMethod(std::string id, handleType *handle){
            return ((*handle = Model::LAEMethodStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEMETHOD, id))) > 0);
        };
        static bool getMethodStage(std::string id, handleType *handle){
            return ((*handle = Model::LAEMethodStageStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEMETHODSTAGE, id))) > 0);
        };
        static bool getMethodStageProgression(std::string id, handleType *handle){
            return ((*handle = Model::LAEMethodStageProgressionStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEMETHODSTAGEPROGRESSION, id))) > 0);
        };
        static bool getProperty(std::string id, handleType *handle){
            return ((*handle = Model::LAEPropertyStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEPROPERTY, id))) > 0);
        };
        static bool getPropertySource(std::string id, handleType *handle){
            return ((*handle = Model::LAEPropertySourceStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEPROPERTYSOURCE, id))) > 0);
        };
        static bool getAPIGroup(std::string id, handleType *handle){
            return ((*handle = Model::APIGroupStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_APIGROUP, id))) > 0);
        };
        static bool getAPIMethod(std::string id, handleType *handle){
            return ((*handle = Model::APIMethodStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_APIMETHOD, id))) > 0);
        };
        static bool getAPIParameter(std::string id, handleType *handle){
            return ((*handle = Model::APIParameterStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_APIPARAMETER, id))) > 0);
        };
        static bool getAPIVariable(std::string id, handleType *handle){
            return ((*handle = Model::APIVariableStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_APIVARIABLE, id))) > 0);
        };
        static bool getAPIException(std::string id, handleType *handle){
            return ((*handle = Model::APIExceptionStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_APIEXCEPTION, id))) > 0);
        };
        static bool getAPIReturn(std::string id, handleType *handle){
            return ((*handle = Model::APIReturnStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_APIRETURN, id))) > 0);
        };
        static bool getValueGroup(std::string id, handleType *handle){
            return ((*handle = Model::LAEValueGroupStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEVALUEGROUP, id))) > 0);
        };
        static bool getValueType(std::string id, handleType *handle){
            return ((*handle = Model::LAEValueTypeStore.getExistingHandle(
                         Hashable::hashObject(OBJECT_LAEVALUETYPE, id))) > 0);
        };

        static bool getPolicy(std::string id, LAEPolicy **object){
            handleType handle;
            if(getPolicy(id, &handle)){
                *object = Model::LAEPolicyStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getClass(std::string id, LAEClass **object){
            handleType handle;
            if(getClass(id, &handle)){
                *object = Model::LAEClassStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getTrigger(std::string id, LAETrigger **object){
            handleType handle;
            if(getTrigger(id, &handle)){
                *object = Model::LAETriggerStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getRequirement(std::string id, LAERequirement **object){
            handleType handle;
            if(getRequirement(id, &handle)){
                *object = Model::LAERequirementStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getChecker(std::string id, LAEChecker **object){
            handleType handle;
            if(getChecker(id, &handle)){
                *object = Model::LAECheckerStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getFunction(std::string id, LAEFunction **object){
            handleType handle;
            if(getFunction(id, &handle)){
                *object = Model::LAEFunctionStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getPropertyReference(std::string id, LAEPropertyReference **object){
            handleType handle;
            if(getPropertyReference(id, &handle)){
                *object = Model::LAEPropertyReferenceStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getMethod(std::string id, LAEMethod **object){
            handleType handle;
            if(getMethod(id, &handle)){
                *object = Model::LAEMethodStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getMethodStage(std::string id, LAEMethodStage **object){
            handleType handle;
            if(getMethodStage(id, &handle)){
                *object = Model::LAEMethodStageStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getMethodStageProgression(std::string id, LAEMethodStageProgression **object){
            handleType handle;
            if(getMethodStageProgression(id, &handle)){
                *object = Model::LAEMethodStageProgressionStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getProperty(std::string id, LAEProperty **object){
            handleType handle;
            if(getProperty(id, &handle)){
                *object = Model::LAEPropertyStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getPropertySource(std::string id, LAEPropertySource **object){
            handleType handle;
            if(getPropertySource(id, &handle)){
                *object = Model::LAEPropertySourceStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getAPIGroup(std::string id, APIGroup **object){
            handleType handle;
            if(getAPIGroup(id, &handle)){
                *object = Model::APIGroupStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getAPIMethod(std::string id, APIMethod **object){
            handleType handle;
            if(getAPIMethod(id, &handle)){
                *object = Model::APIMethodStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getAPIParameter(std::string id, APIParameter **object){
            handleType handle;
            if(getAPIParameter(id, &handle)){
                *object = Model::APIParameterStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getAPIVariable(std::string id, APIVariable **object){
            handleType handle;
            if(getAPIVariable(id, &handle)){
                *object = Model::APIVariableStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getAPIException(std::string id, APIException **object){
            handleType handle;
            if(getAPIException(id, &handle)){
                *object = Model::APIExceptionStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getValueGroup(std::string id, LAEValueGroup **object){
            handleType handle;
            if(getValueGroup(id, &handle)){
                *object = Model::LAEValueGroupStore.getValue(handle);
                return true;
            } else
                return false;
        };
        static bool getValueType(std::string id, LAEValueType **object){
            handleType handle;
            if(getValueType(id, &handle)){
                *object = Model::LAEValueTypeStore.getValue(handle);
                return true;
            } else
                return false;
        };
