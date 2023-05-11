from arena import Arena

# Avoid using this
class Game:
    def __init__(self) -> None:
        self.current_arena = 1

        self.arena_1 = 'arena_1.txt'   
    
    def createArena(self):
        self.arena = Arena(self.arena_1)
        self.arena.readArena()
        self.arena.printArena()
    

def main():
    currentArena = 1
    arena_1 = 'arena_1.txt'
    arena = Arena(arena_1)

    arena.readArena()
    arena.printArena()

if __name__ == "__main__":
    main()