package game;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;

public class MapGenerator {
    public int map[][];
    public int brickWidth;
    public int brickHeight;

    public MapGenerator(int row,int col) {
        map = new int[row][col];

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                map[i][j]=1;
            }
        }

        brickWidth = 540/col;
        brickHeight = 150/row;



    }


    public void setBrick(int value,int r, int c) {
        map[r][c] = value;
    }

    public void draw(Graphics2D g) {
//        for(int i=0;i<map.length;i++) {
//            for(int j=0;j<map[0].length;j++) {
//                if(map[i][j]>0) {
//                    g.setColor(Color.red.darker().darker());
//                    g.fillRect(j*brickWidth+80, i*brickHeight+50, brickWidth, brickHeight);
//
//                    g.setColor(Color.cyan.lightGray);
//                    g.setStroke(new BasicStroke(3));
//
//                    g.drawRect(j*brickWidth+80, i*brickHeight+50, brickWidth, brickHeight);				}
//            }
//        }
        for(int i=0;i<13;i++){
            if(i==3 || i==7 ){
                g.setColor(Color.cyan.lightGray);
            }
            else{
                g.setColor(Color.red.darker().darker());
            }

            g.fillRect(i*40+90,50,40,15);
            g.setColor(Color.cyan.lightGray);
            g.drawRect(i*40+90,50,40,15);
        }

        for(int i=0;i<7;i++){
            if(i==3 || i==7 ){
                g.setColor(Color.cyan.lightGray);
            }
            else{
                g.setColor(Color.red.darker().darker());
            }
            g.fillRect(i*40+90,50+150,40,15);
            g.setColor(Color.cyan.lightGray);
            g.drawRect(i*40+90,50+150,40,15);
        }
        for(int j=1;j<10;j++){
            g.setColor(Color.red.darker().darker());
            g.fillRect(40*1+90,50+15*j,40,15);
            g.setColor(Color.cyan.lightGray);
            g.drawRect(40*1+90,50+15*j,40,15);
            g.setColor(Color.red.darker().darker());
            g.fillRect(40*5+90,50+15*j,40,15);
            g.setColor(Color.cyan.lightGray);
            g.drawRect(40*5+90,50+15*j,40,15);
            g.setColor(Color.red.darker().darker());
            g.fillRect(40*10+90,50+15*j,40,15);
            g.setColor(Color.cyan.lightGray);
            g.drawRect(40*10+90,50+15*j,40,15);
            if(j==9){
                g.setColor(Color.red.darker().darker());
                g.fillRect(40*10+90,50+15*(j+1),40,15);
                g.setColor(Color.cyan.lightGray);
                g.drawRect(40*10+90,50+15*j,40,15);

            }
        }


    }

}




