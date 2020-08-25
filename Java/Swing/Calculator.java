
//Bisogna implementare la Frame del calcolatore:
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPanel;
import java.awt.Container;
public class Calculator extends JFrame {
	public Calculator() {
	super();
	setBounds(200, 100, 400, 120);
	JPanel ui = createUI(); // crea l’interfaccia grafica
	Container c = this.getContentPane();
	c.add(ui);
	setTitle("Mini Calcolatrice");
	setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	setVisible(true);
	}
	
	public static void main(String[] args) {
		Calculator calc = new Calculator();
	}
	
	private JPanel createUI() {
			JPanel pannello = new JPanel();
			// Creo componenti
			CalcDisplay testo = new CalcDisplay(15);
			testo.setHorizontalAlignment(JTextField.RIGHT); // Setto l’allineamento del testo
			CalcButton calc = new CalcButton("=");
			CalcButton canc = new CalcButton("C");
			CalcButton sum = new CalcButton("+");
			CalcButton sub = new CalcButton("-");
			CalcButton div = new CalcButton("/");
			CalcButton mul = new CalcButton("*");
			// Aggiungo i componenti al pannello
			pannello.add(testo);
			pannello.add(sum);
			pannello.add(sub);
			pannello.add(div);
			pannello.add(mul);
			pannello.add(calc);
			pannello.add(canc);
			CalcEngine engine = new CalcEngine(testo); // Istanzio l’ascoltatore di eventi
			// Setto engine come l’ascoltatore per i bottoni
			sum.addActionListener(engine);
			sub.addActionListener(engine);
			mul.addActionListener(engine);
			div.addActionListener(engine);
			calc.addActionListener(engine);
			canc.addActionListener(engine);
			return pannello;
		
		}
}
