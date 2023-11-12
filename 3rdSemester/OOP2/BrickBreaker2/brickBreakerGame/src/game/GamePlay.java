package game;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class GamePlay extends JPanel implements ActionListener, KeyListener {
        private boolean play = false;
        private int score;
        private  int totalBrick = 21;
        private Timer timer;
        private int delay =8;
        private int ballposX = 120;
        private int ballposY = 350;
        private int ballXdir = -1;
        private int ballYdir =-2;
        private int playerX = 350;

        private MapGenerator m;

        public GamePlay(){
                addKeyListener(this);
                setFocusable(true);
                setFocusTraversalKeysEnabled(true);

                timer = new Timer(delay,this);
                timer.start();
                m=new MapGenerator(3,7);
        }

        public void paint(Graphics g){
                //canvas
                g.setColor(Color.cyan.lightGray);
                g.fillRect(1,1,692,592);

                //border
                g.setColor(Color.orange);
                //top
                g.fillRect(0,0,692,3);
                //left
                g.fillRect(0,3,3,592);
                //right
                g.fillRect(687,3,3,592);

                //paddle
                g.setColor(Color.magenta.darker().darker().darker());
                g.fillRect(playerX, 550, 100, 8);

                //bricks
                m.draw((Graphics2D)g);

                //ball
                g.setColor(Color.blue.darker().darker());
                g.fillOval(ballposX,ballposY,20,20);

                //score
                g.setColor(Color.GREEN.darker().darker());
                g.setFont(new Font("serif",Font.BOLD,20));
                g.drawString("Score : "+score,550,30);

                //gameover
                if(ballposY>=570){
                        play=false;
                        ballXdir=0;
                        ballYdir=0;

                        g.setColor(Color.red);
                        g.setFont(new Font("serif",Font.BOLD,20));
                        g.drawString("Game Over!!, Score : "+score,200,300);


                        g.setColor(Color.red);
                        g.setFont(new Font("serif",Font.BOLD,25));
                        g.drawString("Press Enter to Restart ! ",170,350);
                }

                if(totalBrick<=0){
                        play=false;
                        ballXdir=0;
                        ballYdir=0;

                        g.setColor(Color.red);
                        g.setFont(new Font("serif",Font.BOLD,20));
                        g.drawString("You Won!!, Score : "+score,200,300);


                        g.setColor(Color.red);
                        g.setFont(new Font("serif",Font.BOLD,25));
                        g.drawString("Press Enter to Restart ! ",170,350);
                }
        }


        @Override
        public void actionPerformed(ActionEvent e) {
                if(play){

                        if(ballposX<=0)
                                ballXdir = -ballXdir;
                        if(ballposX>=670)
                                ballXdir = -ballXdir;
                        if(ballposY<=0)
                                ballYdir = -ballYdir;

                        Rectangle ballRect = new Rectangle(ballposX,ballposY,20,20);
                        Rectangle playerRect = new Rectangle(playerX,550,100,8);

                        if(ballRect.intersects(playerRect)){
                                ballYdir = -ballYdir;
                        }

                       A: for(int i=0;i<m.map.length;i++){
                                for(int j=0;j<m.map[0].length;j++){
                                        if(m.map[i][j]>0){
                                                int width = m.brickwWidth;
                                                int height = m.brickHeight;
                                                int brickXpos = 80+j*width;
                                                int brickYpos = 50 +i*height;

                                                Rectangle brickRect = new Rectangle(brickXpos,brickYpos,width,height);

                                                if(ballRect.intersects(brickRect)){
                                                        m.setBrick(0,i,j);
                                                        totalBrick--;
                                                        score +=5;

                                                        if(ballposX+19 <=brickXpos || ballposX+1>=brickXpos+width){
                                                                ballXdir = - ballXdir;
                                                        }else
                                                                ballYdir = - ballYdir;

                                                        break A;
                                                }
                                        }
                                }
                        }




                        ballposX +=ballXdir;
                        ballposY +=ballYdir;
                }
                repaint();
        }

        private void moveLeft(){
                play = true;
                playerX -=20;
        }
        private void moveRight(){
                play = true;
                playerX +=20;
        }

        @Override
        public void keyPressed(KeyEvent e) {
                if(e.getKeyCode()==KeyEvent.VK_LEFT){
                        if(playerX <=0)
                                playerX =0;
                        else
                                moveLeft();
                }
                if(e.getKeyCode()==KeyEvent.VK_RIGHT){
                        if(playerX>=600)
                                playerX = 600;
                        else
                                moveRight();
                }
                if(e.getKeyCode() == KeyEvent.VK_ENTER){
                        if(!play){
                                score =0;
                                totalBrick = 21;
                                ballposX = 120;
                                ballposY = 350;
                                ballXdir = -1;
                                ballYdir = -2;
                                playerX = 320;

                                m = new MapGenerator(3,7);
                        }
                }
                repaint();
        }

        @Override
        public void keyReleased(KeyEvent e) {}
        @Override
        public void keyTyped(KeyEvent e) {}
}
