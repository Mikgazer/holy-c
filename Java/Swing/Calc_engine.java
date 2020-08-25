
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class CalcEngine implements ActionListener {
	
	private CalcDisplay display; // Display della calcolatrice
	private double result; // Risultato
	private String precOp; // Operazione da eseguire
	public CalcEngine(CalcDisplay dis) {
	display = dis;
	precOp = "nop";
	result = 0;
}
public void actionPerformed(ActionEvent ev) {
	double valore = Double.parseDouble(display.getText());
	display.setText("");
	display.requestFocus();
	String operazione = ev.getActionCommand();
	if (operazione.equals("C")) {
	result = 0;
	valore = 0;
	precOp = "nop";
	} else {
	if (precOp.equals("+")) {
	result += valore;
	} else if (precOp.equals("-")) {
	result -= valore;
	} else if (precOp.equals("*")) {
	result *= valore;
	} else if (precOp.equals("/")) {
	result /= valore;
	} else if (precOp.equals("nop")) {
	result = valore;
	}
	display.setText("" + result);
	precOp = operazione;
	}

}
