if (maze[originX + 1][originY] == 'r')
    {
        visit(maze, route, originX + 1, originY);
    }
    if (maze[originX][originY + 1] == 'r')
    {
        visit(maze, route, originX, originY + 1);
    }
    if (maze[originX][originY-1] == 'r')
    {
        visit(maze, route, originX , originY-1);
    }
    if (maze[originX-1][originY ] == 'r')
    {
        visit(maze, route, originX-1, originY );
    }
    if (route[originX][originY] == 0)
    {
        route[originX][originY] = 1;
    }