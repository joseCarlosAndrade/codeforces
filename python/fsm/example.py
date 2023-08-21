'''
Usage example: simple FSM

Stopped -- start --> Moving (repeat until 'wall' is inserted to event list) -- target_reached --> Stopped (returns to start)
                      ^ |
                      | | (wall)
                      | v
                   BreakingWall (repeat until wall is not on event list anymore)


'''
from state import State

class Stopped(State):
    def __init__(self, name="") -> None: # remove? maybe not necessary
        super().__init__(name)
    
    def event(self):
        if State.eventOp(2, 'start') and not State.eventOp(2, 'target_reached'):
            
            return Moving()


        return self

class Moving(State):
    def __init__(self, name="") -> None:
        super().__init__(name)
    
    def event(self):
        if State.eventOp(2, 'wall'):
            return BreakingWall()
        
        elif State.eventOp(2, 'target_reached'):
            return Stopped()

class BreakingWall(State):
    def __init__(self, name="") -> None:
        super().__init__(name)
    
    def event(self):
        if State.eventOp(2, 'wall'):
            return self
    
        else:
            return Moving()
    
car = Stopped()
while True:
   

    if car == 'Stopped' and car.eventOp(4) == []:
        car.eventOp(0, 'start')

    if car == 'Moving':
        print(car)

        car.eventOp(0, 'wall')


    car = car.event()