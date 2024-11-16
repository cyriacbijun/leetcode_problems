def floodFill( image, sr: int, sc: int, color: int):
        oldC = image[sr][sc]
        if oldC == color:
            return image
        n = len(image)
        m = len(image[0])
        def fillColor(r,c):
            if(0 <= r < n and 0<= c < m and image[r][c] == oldC):
                image[r][c] = color
                fillColor(r,c+1)
                fillColor(r,c-1)
                fillColor(r+1,c)
                fillColor(r-1,c)
        fillColor(sr,sc)
        return image