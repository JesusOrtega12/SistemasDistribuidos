import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ServidorCalculadora extends UnicastRemoteObject implements ServicioCalculadora {
    public ServidorCalculadora() throws RemoteException {
        super();
    }

    public float suma(float x, float y) throws RemoteException {
	System.out.println("Haciendo la operacion: "+ x +"+" +y);        
	return x+y;
    }

    public float resta(float x, float y) throws RemoteException {
	System.out.println("Haciendo la operacion: "+ x +"-" +y);        
	return x-y;
    }

    public float multiplicacion(float x, float y) throws RemoteException {
	System.out.println("Haciendo la operacion: "+ x +"x" +y);        
	return x*y;
    }

    public float division(float x, float y) throws RemoteException {
	System.out.println("Haciendo la operacion: "+ x +"/" +y);        
	return x/y;
    }
}
