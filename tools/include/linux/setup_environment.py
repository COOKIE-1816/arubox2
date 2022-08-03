def boardSelector():
    isMainBoard = input("Are you editing configuration for manager board? [y/N]")
    isMainBoard = not isMainBoard == "Y" and not isMainBoard == "y"

