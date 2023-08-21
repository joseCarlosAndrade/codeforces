'''
Usage example: simple FSM

Stopped -- start --> Moving (repeat until 'wall' is inserted to event list) -- target_reached --> Stopped (returns to start)
                      ^  |
                      |  | (wall)
                      |  v
                   BreakingWall (repeat until wall is not on event list anymore)


'''
from state import State
import time

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
    
# code

walls = 2
car = Stopped("nome")
while True:
    time.sleep(3)
    # print(car)
    print(f'\n==========================================\n \
Current state and event list: {car}; Event List: {car.eventOp(-1)}\n\n')
   

    if car == 'Stopped' and not car.eventOp(2, 'target_reached'):
        print(car, 'Adding start to the event list...')
        # do stuff to start
        car.eventOp(0, 'start')
    
    if car == 'Stopped' and car.eventOp(2, 'target_reached'): # if stopped and target is reached, finish
        print('Stopped with target reached: exiting cycle..')
        break

    if car == 'Moving':
        # print(car)
        if walls > 0:
            walls -= 1
            # do stuff to encounter wall
            print('Encountered a wall, adding wall to event list..')
            car.eventOp(0, 'wall')
            
        else:
            # do stuff to reach target
            print('Target reached, adding target_reached to event list..')
            car.eventOp(0, 'target_reached')

    
    if car == 'BreakingWall':
        # print(car)
        # do stuff to break wall
        print('Breaking wall..')
        time.sleep(3)
        print('Wall broke, popping wall from event list...')
        car.eventOp(3)
    

    
    car = car.event() # updates state based on stored events


print(f"Cycle is finished. Event list: {car.eventOp(-1)}")