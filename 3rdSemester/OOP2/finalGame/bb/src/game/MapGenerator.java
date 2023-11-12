package game;

import java.awt.*;

public class MapGenerator {
    public int map[][];
    public int brickwWidth;
    public int brickHeight;

    public MapGenerator(int row,int col){
        map = new int[11][13];



        brickwWidth=40;
        brickHeight=15;
        mapInitialization();
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
                    g.setStroke(new BasicStroke(2));
                    g.drawRect(j*brickwWidth+80,i*brickHeight+50,brickwWidth,brickHeight);
                }
            }
        }








    }
    private void mapInitialization(){
        for(int i=0;i<13;i++){
            if(i==3 || i==7 ){
                map[0][i]=0;
            }
            else{

                map[0][i]=1;
            }


        }

        for(int i=0;i<13;i++){
            if(i==3 || i==7 || i==8 || i==9 || i==11 || i==12){

                map[10][i]=0;
            }
            else{

                map[10][i]=1;
            }
        }

        for(int i=1;i<10;i++){
            for(int j=0;j<13;j++){
                if(j==1 || j==5 || j==10){

                    map[i][j]=1;
                }
                else {

                    map[i][j]=0;
                }



            }
        }
    }



}
