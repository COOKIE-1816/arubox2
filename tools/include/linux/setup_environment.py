def boardSelector():
    isMainBoard = input("Are you editing configuration for manager board? [y/N]")
    isMainBoard = not isMainBoard == "Y" and not isMainBoard == "y"

def listf():
    if not isMainBoard:
        listfile = open("./include/setup_variables_manager.txt", "r")
    else:
        listfile = open("./include/setup_variables_board.txt", "r")
        
    print(listfile.read())
    listfile.close()