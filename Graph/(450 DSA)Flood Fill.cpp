 void colorFill(vector<vector<int>> &image, int sr, int sc, int newColor,int beg)
    {
        
        if(sr<0||sr>=image.size()||sc<0||sc>=image[0].size()||image[sr][sc]!=beg||image[sr][sc]==newColor)
            return;
        // else
            image[sr][sc]=newColor;

        colorFill(image,sr+1,sc,newColor,beg);
        colorFill(image,sr-1,sc,newColor,beg);
        colorFill(image,sr,sc+1,newColor,beg);
        colorFill(image,sr,sc-1,newColor,beg);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
           colorFill(image,sr,sc,newColor,image[sr][sc]);
        return image;
        
    }
