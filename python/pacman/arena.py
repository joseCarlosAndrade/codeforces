import os

class Arena:
    def __init__(self, arena) -> None:
        self.arena_file = arena
        self.arena_board = 'Not defined yet'
        self.swipe_char = '\x1b[H'

        self.cur_path = os.path.dirname(os.path.abspath(__file__))

    def readArena(self) -> None:
        self.arena_board = []
        with open(f"{self.cur_path}/arenas/{self.arena_file}", '+r') as file:
            while True:
                line = file.readline()  

                if line[0] == "%":
                    break
                
                self.arena_board.append(line)
    
    def printArena(self) -> None:
        print(self.swipe_char)

        # Print every row except the new line character
        for row in self.arena_board:
            print(row[:-1])