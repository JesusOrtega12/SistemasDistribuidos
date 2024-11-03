import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class ServidorRMI {
    public static void main(String[] args) {
        try {
	    System.setProperty("java.rmi.server.hostname", "10.86.13.247");
            ServicioCalculadora servicio = new ServidorCalculadora();
	    LocateRegistry.createRegistry(1099); // Puerto predeterminado para RMI
            Naming.rebind("ServicioCalculadora", servicio); // Registra el servicio en el registro RMI
            System.out.println("Servidor RMI iniciado.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
