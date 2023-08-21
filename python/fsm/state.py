class State:
    '''
    Class that represents what is a state. It must be inherited by all state childs classes.
    It creates static methods and elements that are shared by all children.
    '''
    __allowedOperations = [-1, 0, 1, 2, 3, 4]

    __eventList = []

    # operationMethods = {
    #     0 : State.opAdd,

    # }
    

    def __init__(self, name="") -> None:
        self.name = name # talvez seja util? nao sei, ponderar depois
        

    def __repr__(self) -> str:
        return "null" #ignorar eu tava experimentando funcoes
    
    @classmethod
    def __eq__(cls,comparison):
        return cls.__name__ == comparison
    
    @staticmethod
    def opAdd(data :str):
        pass

    @staticmethod
    def eventOp(operation : int, data :str = ""):
        '''
        Handles the event list operation and it's layed like:\n
            -1 -> return an array with all th events \n
            0 -> add operation; param: str (event)\n
            1 -> remove operation; param: str (event)\n
            2 -> checks if event (str) is in event list\n
            3 -> pop operation; para: str (event)\n
            4 -> clear operation; clear the entire array\n

            >>> SomeState.eventOp(0, "read_all_bases") # adds the event\
                             read_all_bases to the event list

        '''

        if operation not in State.__allowedOperations:
            raise Exception("Operation not found")
        
        # {}
        if operation == 0: # Add
            State.__eventList.append(data)

        elif operation == 1: # Remove
            if data in State.__eventList:
                State.__eventList.remove(data)
            
            else:
                print("Event not in list")
        
        elif operation == 2: # Check if in list
            if data in State.__eventList:
                return True
            
            return False

        elif operation == 3: # Pop
            if len(State.__eventList) > 0:
                State.__eventList.pop()
            else:
                print("Event list empty")

        elif operation == 4: # Clear all
            State.__eventList = []
            
        elif operation == -1:
            return State.__eventList

    @classmethod
    def __str__(cls) -> str:
        '''Returns the name of the state by getting its name.
        Each child state class must have names layed like:
        
        >>> class StateName(State):
            \'\'\'StateDocumentation\'\'\'
        '''
        return cls.__name__
    
    def getName(self):
        return self.name

    # @classmethod
    # def __doc__(cls):
    #     return cls.__doc__


if __name__ == "__main__":

    class StateOne(State):
        '''
        StateOne documentation
        '''
        def __init__(self, name) -> None:
            super().__init__(name)

        def event(self):
            # conditions
            pass

    class StateTwo(State):
        def __init__(self, name="") -> None:
            super().__init__(name)




    a = StateOne("flying")
    b = StateTwo("landing")
    print(a, b)
    a.eventOp(0, "reached") 
    a.eventOp(0, "on_base") 
    print(a.eventOp(-1))
    b.eventOp(0, "landed")
    print(b.eventOp(-1))
    b.eventOp(2)
    print(a.eventOp(-1))

    if a == 'StateOne':
        print(f"igual: {a}")
    else:
        print('not')
    '''
    Output:
    >>> StateOne StateTwo
    >>> ['reached', 'on_base']
    >>> ['reached', 'on_base', 'landed']
    >>> ['reached', 'on_base']
    '''