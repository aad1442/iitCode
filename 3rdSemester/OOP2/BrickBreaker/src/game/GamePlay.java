package game;


import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JPanel;
import javax.swing.Timer;

public class GamePlay extends JPanel implements ActionListener,KeyListener{
	private boolean play = false;
	private int totalBricks = 21;
	private int score = 0;
	private Timer timer;
	private int delay =5;
	private int ballposX = 120;
	private int ballposY = 350;
	private int ballXdir =-1;
	private int ballYdir = -1;
	private int playerX = 350;
	private MapGenerator mg;
	
	public GamePlay() {
        // Add the KeyListener to this JPanel
        addKeyListener(this);
        setFocusable(true); // Enable focus on this component
        setFocusTraversalKeysEnabled(true);
		timer = new Timer(delay,this);
		timer.start();
		mg = new MapGenerator(3,7);
	}
	
	
	public void paint(Graphics g) {
		g.setColor(Color.cyan.lightGray);
		g.fillRect(0,0,700,600);
		
		g.setColor(Color.orange);
		g.fillRect(0,0,700,3);
		
		g.fillRect(0,0,3,600);
		
		
		//g.fillRect(687,3,3,600);
		g.fillRect(687,0,3,600);
		
		
		g.setColor(Color.magenta.darker().darker().darker());
		g.fillRect(playerX, 550, 100, 8);
		
		//bricks
		mg.draw((Graphics2D) g);
		
		
		//ball
		g.setColor(Color.blue.darker().darker());
		g.fillOval(ballposX, ballposY,20, 20);
		
		g.setColor(Color.green);
		g.drawString("Score : ", 550, 30);
		
		
		
	}

	@Override
	public void keyTyped(KeyEvent e) {}
	
	private void moveLeft() {
		play = true;
		playerX -= 20;
	}
	private void moveRight() {
		play = true;
		playerX += 20;
	}

	@Override
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode()== KeyEvent.VK_LEFT) {
			if(playerX <= 0)
				playerX =0;
			else
				moveLeft();
		}
		else if(e.getKeyCode() == KeyEvent.VK_RIGHT){
			if(playerX >=600)
				playerX = 600;
			else
				moveRight();
		}
		repaint();
		
		
	}
	

	@Override
	public void keyReleased(KeyEvent e) {}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(play) {
			if(ballposX <=0) {
				ballXdir =- ballXdir;
				
			}
			if(ballposX >=680) {
				
				ballXdir = -ballXdir;
			}
			if(ballposY <=0) {
				ballYdir = - ballYdir;
			}
			Rectangle ballRect = new Rectangle(ballposX,ballposY,20,20);
			Rectangle paddleRect = new Rectangle(playerX,550,100,8);
			
			A:for(int i=0;i<mg.map.length;i++) {
				for(int j=0;j<mg.map[0].length;j++) {
					if(mg.map[i][j]>0) {
						int width = mg.brickWidth;
						int height = mg.brickHeight;
						int brickXpos = 80 + j*width;
						int brickYpos = 50 + i*height;
						
						Rectangle brickRect = new Rectangle(brickXpos,brickYpos,width,height);
						
						if(ballRect.intersects(brickRect)) {
							mg.setBrick(0,i,j);
							totalBricks --;
							
							if(ballposX +19 <=brickXpos|| ballposX+1>= brickXpos+width) {
								ballXdir = - ballXdir;
							}
							else {
								ballYdir = -ballYdir;
							}
							break A;
						}
					}
				}
			}
			
			if(ballRect.intersects(paddleRect)) {
				ballYdir =- ballYdir;
			}
			
			ballposX += ballXdir;
			ballposY += ballYdir;
			
			repaint();
		}
 }


	
}



