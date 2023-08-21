from state import State

'''
Phase 1 structure

(( Landed )) --init--> (( TakeOff )) --InAir--> (( GoToShelf )) --
   ^                                                ^            |
   |                                                |        arrived
   |                                            read_again       |
   |                                                |            v
   |- land ---- (( GoToBase )) <----- read_all <-- ((  ReadShelf  ))
                                                    ^            |
                                                    |            |
                                                    |-- read_1 --|    obs. (read_1, 2, 3)
'''

class Landed(State):
    '''
    Initial and closure state. If read_all not in event list, go to TakeOff.
    Otherwise it finishes its loop.
    '''
    def __init__(self, name="") -> None:
        super().__init__(name)
    
    def event(self):
        '''
        Instance method
        '''



class TakeOff(State):
    '''
    Takes off if init is requested. 
    '''
    def __init__(self,name="") -> None:
        super().__init__(name)


class GoToShelf(State):
    '''
    Redirects the drones path so it goes to the upper left corner of the shelf.
    '''
    def __init__(self,name="") -> None:
        super().__init__(name)


class ReadShelf(State):
    '''
    Initializes the reading routine, and only stops if read_all is on the event list.
    '''
    def __init__(self,name="") -> None:
        super().__init__(name)


class GoToBase(State):
    '''
    After reading all OR requested, goes to initial base so it can land later.
    '''
    def __init__(self,name="") -> None:
        super().__init__(name)