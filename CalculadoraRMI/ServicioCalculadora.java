import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ServicioCalculadora extends Remote {
    float suma(float x, float y) throws RemoteException;
    float resta(float x, float y) throws RemoteException;
    float multiplicacion(float x, float y) throws RemoteException;
    float division(float x, float y) throws RemoteException;
}
