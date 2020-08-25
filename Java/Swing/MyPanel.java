import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.Font;
public class MyPanel extends JPanel {
	
	public MyPanel() {
		super();
		setBackground(Color.WHITE);
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(Color.BLUE);
		g.fillRect(5, 10, 100, 130);
		g.setColor(Color.ORANGE);
		g.fillRoundRect(110, 10, 280, 100, 20, 20);
		g.setColor(Color.RED);
		g.drawOval(50, 100, 150, 150);
		g.setColor(Color.GREEN);
		g.fillOval(150, 300, 150, 100);
		g.setColor(Color.BLACK);
		g.drawLine(50, 430, 300, 430);
		g.drawLine(30, 330, 270, 280);
		g.setColor(Color.WHITE);
		g.setFont(new Font("Garamond", Font.BOLD, 50));
		g.drawString("Panel Test", 110, 75);
		g.setColor(Color.CYAN);
		int[] x = new int[]{380, 315, 210, 340};
		int[] y = new int[]{200, 260, 220, 225};
		g.drawPolyline(x, y, 4);
	}
}
