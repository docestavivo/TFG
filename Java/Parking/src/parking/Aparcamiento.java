package parking;

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;

public class Aparcamiento implements Serializable {

    private int plazasAparcamiento = 5;
    private final HashMap<String, Vehiculo> plazas = new HashMap<>();

    public void introducirVehiculo(Vehiculo v) throws AparcamientoException {
        try {
            if ((plazasAparcamiento > 0)) {
                if (!(plazas.containsKey(v.getMatricula()))) {
                    plazasAparcamiento--;
                    plazas.put(v.getMatricula(), v);
                } else {
                    throw new AparcamientoException(AparcamientoException.VEHICULO_DENTRO);
                }
            } else {
                throw new AparcamientoException(AparcamientoException.APARCAMIENTO_LLENO);
            }
        } catch (AparcamientoException e) {
            System.err.println(e.toString());
        }

    }
    
    public String estadistica(){
        int contTurismo=0;
        int contFurgoneta=0;
        int contTodoterreno=0;
        Automovil coche= new Automovil();
        
        
        String stats;
        Iterator<Vehiculo> i = plazas.values().iterator();
        while (i.hasNext()){
            switch (coche.getTipo()) {
                case "Turismo":
                    contTurismo++;
                    break;
                case "Todoterreno":
                    contTodoterreno++;
                    break;
                case "Furgoneta":
                    contFurgoneta++;
                    break;
            }
            }
        
        
        stats="TURISMOS APARCADOS: "+contTurismo+
                " TODOTERRENOS APARCADOS: "+contTodoterreno+
                " FURGONETAS APARCADAS: "+contFurgoneta;
        
        return stats;
    }

    public void sacarVehiculo(String matricula) throws AparcamientoException, IOException {
        try {
            if (plazas.containsKey(matricula)) {
                Vehiculo aux = (plazas.get(matricula));
                plazasAparcamiento++;
                plazas.remove(matricula);
                aux.setSalida(Calendar.getInstance().getTime());
                generarTicket(aux);
            } else {
                throw new AparcamientoException(AparcamientoException.VEHICULO_FUERA);
            }
        } catch (AparcamientoException e) {
            System.err.println(e.toString());
        }

    }
    
    
    private void generarTicket(Vehiculo aux ) throws IOException{
        String matricula=aux.getMatricula();
        
        Date fechaEntrada= aux.getEntrada();
        Date fechaSalida= aux.getSalida();
        
        double minutosTranscurridos=aux.getMinutos();
        double importe=aux.calcularImporte();
        
        Ticket ticket = new Ticket(matricula,fechaEntrada,fechaSalida,minutosTranscurridos,importe);
                
        ticket.VolcarAFichero();
        
        
        
    }
    

    public Aparcamiento RecuperarDatosDesdeFichero() throws FileNotFoundException, IOException, ClassNotFoundException {

        try (FileInputStream fis = new FileInputStream("Aparcamiento.dat")) {
            ObjectInputStream ois = new ObjectInputStream(fis);
            try {
                while (true) {
                    return (Aparcamiento) ois.readObject();
                }
            } catch (EOFException e) {
                System.out.println("Lectura de los objetos de tipo Persona finalizada");
            }

        } catch (Exception e) {
            VolcarDatosAFichero();
        }

        return null;

    }

    public void VolcarDatosAFichero() throws FileNotFoundException, IOException {

        try (FileOutputStream fos = new FileOutputStream("Aparcamiento.dat")) {
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(this);
        }
    }

}
