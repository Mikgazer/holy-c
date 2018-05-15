
public class Automobile extends Veicoli {

	public final int NRuote = 4;
	
	private String targa;
	
	private boolean avviata = false;
	
	public Automobile(String t) {
		this.targa = t;
		this.setNRoute(NRuote);
	}
	
	public void avvia() {
		avviata = true;
	}
	public void spegni() {
		avviata = false;
	}
	
	public void accelera(double accelerazione, int secondi) {
		if(avviata)	
		{
			this.setVelocita(this.getVelocita() + accelerazione * secondi);
		}
	}
	
}
