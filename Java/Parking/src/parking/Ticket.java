/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package parking;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Date;

/**
 *
 * @author Estefania
 */
public class Ticket implements Serializable {

    private String matricula;
    private Date fechaEntrada, fechaSalida;
    private double minutos;
    private double importe;

    public Ticket(String matricula,
            Date fechaEntrada,
            Date fechaSalida,
            double minutos,
            double importe) {
        this.matricula = matricula;
        this.fechaEntrada = fechaEntrada;
        this.fechaSalida = fechaSalida;
        this.minutos = minutos;
        this.importe = importe;
    }

    void VolcarAFichero() throws FileNotFoundException, IOException {
        String nombre = "ticket_" + matricula  + ".dat";

        try (FileOutputStream fos = new FileOutputStream(nombre)) {
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(this);
        }

    }
}
