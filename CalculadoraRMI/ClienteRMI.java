import java.rmi.Naming;

public class ClienteRMI {
    public static void main(String[] args) {
        try {
            ServicioCalculadora servicio = (ServicioCalculadora) Naming.lookup("rmi://10.86.13.247/ServicioCalculadora");
	    if(args.length!=3){
	    	System.out.println("Argumentos insuficientes");
	    }else{
	    String operador=args[1];
	    float operando1=Float.parseFloat(args[0]);
	    float operando2=Float.parseFloat(args[2]);
	    float resultado;
	    switch (operador){
		case "+":
			resultado=servicio.suma(operando1,operando2);
			System.out.println("Resultado:"+resultado);
			break;
		case "-":
			resultado=servicio.resta(operando1,operando2);
			System.out.println("Resultado:"+resultado);
			break;
		case "x":
			resultado=servicio.multiplicacion(operando1,operando2);
			System.out.println("Resultado:"+resultado);
			break;
		case "/":
			resultado=servicio.division(operando1,operando2);
			System.out.println("Resultado:"+resultado);
			break;
		default:
			System.out.println("No se puede realizar ninguna operacion");
			break;
	    	}
	    }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
