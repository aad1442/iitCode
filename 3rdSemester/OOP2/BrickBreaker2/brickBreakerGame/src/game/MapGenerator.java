package game;

import java.awt.*;

public class MapGenerator {
    public int map[][];
    public int brickwWidth;
    public int brickHeight;

    public MapGenerator(int row,int col){
        map = new int[row][col];

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                map[i][j]=1;
            }
        }

        brickwWidth=540/col;
        brickHeight=150/row;
    }

    public void setBrick(int value,int r,int c){
        map[r][c]=value;
    }
    public void draw(Graphics2D g){

        for(int i=0;i< map.length;i++){
            for(int j=0;j<map[0].length;j++){
                if(map[i][j]>0){
                    g.setColor(Color.red.darker().darker());
                    g.fillRect(j*brickwWidth+80,i*brickHeight+50,brickwWidth,brickHeight);

                    g.setColor(Color.cyan.lightGray);;
                    g.setStroke(new BasicStroke(3));
                    g.drawRect(j*brickwWidth+80,i*brickHeight+50,brickwWidth,brickHeight);
                }
            }
        }
    }



}
