
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.io.Serializable;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;


public class Libreria implements Serializable {

    /*identificadores: ISBN  */
    private static HashMap<String, LibroTexto> libsTexto = new HashMap();
    private static HashMap<String, LibroLectura> libsLectura = new HashMap();
    private static HashMap<String, Diccionario> diccionarios = new HashMap();

    /*identificador: numSerie*/
    private static HashMap<String, Lector> lectores = new HashMap();

    /* identificador: <contraseña,correo>*/
    private static HashMap<String, String> registrados = new HashMap();
    /* identificador: <correo,cliente>*/
    private static HashMap<String, Cliente> listaClientes = new HashMap();

    private Cliente clienteiniciado;
    private boolean sesioniniciada = false, baja = false;
    private PublicacionDigital librocomprado;
    private Lector lectorcomprado;
    private double descuento;
    private String mesesconsulta;
    private double preciotrasdescuento;
    private String numerotarjeta, mes, año, direccion,formatodescarga;

    /*metodos ADMINISTRATIVOS*/
    /*ALTAS*/
    public void añadirLibroTexto(LibroTexto librotex) {
        libsTexto.put(librotex.getIsbn(), librotex);

    }

    public void añadirLibroLectura(LibroLectura librolec) {
        libsLectura.put(librolec.getIsbn(), librolec);
    }

    public void añadirDiccionarios(Diccionario dicc) {
        diccionarios.put(dicc.getIsbn(), dicc);
    }

    public void añadirLectores(Lector lector) {
        lectores.put(lector.getNumSerie(), lector);
    }
    /*BAJAS*/

    public boolean bajaLibro(String isbn) {
        baja = false;
        if (libsTexto.containsKey(isbn)) {
            libsTexto.remove(isbn);
            baja = true;
        }
        if (libsLectura.containsKey(isbn)) {
            libsLectura.remove(isbn);
            baja = true;
        }
        if (diccionarios.containsKey(isbn)) {
            diccionarios.remove(isbn);
            baja = true;
        }
        return baja;
    }

    public boolean bajaLector(String numserie) {
        baja = false;
        if (lectores.containsKey(numserie)) {
            lectores.remove(numserie);
            baja = true;
        }
        return baja;
    }

    /*----------------------------*/
    public void registrarCliente(Cliente c) {
        registrados.put(c.getPassword(), c.getCorreo());
        listaClientes.put(c.getCorreo(), c);
    }

    public boolean inicioSesion(String correo, String pass) {

        if (registrados.containsKey(pass) && registrados.containsValue(correo)) {
            sesioniniciada = true;
        }
        if (sesioniniciada) {
            clienteiniciado = listaClientes.get(correo);

        }
        return sesioniniciada;
    }

    public void cerrarSesion() {

        sesioniniciada = false;
        clienteiniciado = null;

    }

    public void añadirLTexto(LibroTexto p) {

        libsTexto.put(p.getIsbn(), p);

    }

    public void eliminarLTexto(String isbn) {

        libsTexto.remove(isbn);

    }

    public void añadirLLectura(LibroLectura l) {

        libsLectura.put(l.getIsbn(), l);

    }

    public void eliminarLLectura(String isbn) {

        libsLectura.remove(isbn);

    }

    public void añadirLector(Lector l) {

        lectores.put(l.getNumSerie(), l);

    }

    public void eliminarLector(String numSerie) {

        lectores.remove(numSerie);

    }

    public void añadirDiccionario(Diccionario d) {

        diccionarios.put(d.getIsbn(), d);

    }

    public void eliminarDiccionario(String isbn) {

        diccionarios.remove(isbn);

    }

    public Cliente getClienteiniciado() {
        return clienteiniciado;
    }

    public void setPreciotrasdescuento(double preciotrasdescuento) {
        this.preciotrasdescuento = preciotrasdescuento;
    }

    public void setMes(String mes) {
        this.mes = mes;
    }

    public void setAño(String año) {
        this.año = año;
    }

    public String getMesesconsulta() {
        return mesesconsulta;
    }

    public void setMesesconsulta(String mesesconsulta) {
        this.mesesconsulta = mesesconsulta;
    }

    public void setNumerotarjeta(String numerotarjeta) {
        this.numerotarjeta = numerotarjeta;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public void ComprarLibro(String isbn) {

        if (libsTexto.containsKey(isbn)) {
            librocomprado = libsTexto.get(isbn);

        } else if (libsLectura.containsKey(isbn)) {
            librocomprado = libsLectura.get(isbn);

        } else if (diccionarios.containsKey(isbn)) {
            librocomprado = diccionarios.get(isbn);
        }

    }

    public void ComprarLector(String numserie) {

        if (lectores.containsKey(numserie)) {
            lectorcomprado = lectores.get(numserie);
        }

    }

    public boolean containsTexto(String isbn) {
        boolean contiene;
        if (libsTexto.containsKey(isbn)) {
            contiene = true;
        } else {
            contiene = false;
        }
        return contiene;
    }

    public boolean containsLectura(String isbn) {
        boolean contiene;
        if (libsLectura.containsKey(isbn)) {
            contiene = true;
        } else {
            contiene = false;
        }
        return contiene;
    }

    public boolean containsDicc(String isbn) {
        boolean contiene;
        if (diccionarios.containsKey(isbn)) {
            contiene = true;
        } else {
            contiene = false;
        }
        return contiene;
    }

    public boolean containsLector(String isbn) {
        boolean contiene;
        if (lectores.containsKey(isbn)) {
            contiene = true;
        } else {
            contiene = false;
        }
        return contiene;
    }

    public PublicacionDigital getLibroComprado() {
        return librocomprado;
    }

    public Lector getLectorComprado() {
        return lectorcomprado;
    }

    public void setFormatodescarga(String formatodescarga) {
        this.formatodescarga = formatodescarga;
    }
    

    public void aplicarDescuento(Cliente c) {

        if (c.getProfesor()) {
            if (libsTexto.containsValue(librocomprado)) {
                descuento = 0.2;

            }

        } else if (!c.getProfesor()) {
            if (libsTexto.containsValue(librocomprado) || libsLectura.containsValue(librocomprado)) {
                descuento = 0.1;

            } else if (diccionarios.containsValue(librocomprado)) {
                descuento = 0.05;
            }

        } else {
            descuento = 0.0;
        }

    }

    public double getDescuento() {
        return descuento;
    }

    public void setDescuento(double descuento) {
        this.descuento = descuento;
    }

    public String busquedaMateriaCurso(String materia, int curso) {

        Iterator<LibroTexto> lt = libsTexto.values().iterator();
        HashMap<String, LibroTexto> encontrados = new HashMap();
        
        String cadenafin = "No hay coincidencias";
        
        while (lt.hasNext()) {

            LibroTexto libro = lt.next();

            if (libro.getMateria().equals(materia) && libro.getCurso() == (curso)) {
                encontrados.put(libro.getIsbn(), libro);

            }

        }
        Iterator<LibroTexto> encontradosit = encontrados.values().iterator();
        while (encontradosit.hasNext()) {

            LibroTexto libro2 = encontradosit.next();

            cadenafin = libro2.toStringA();
        }

        return cadenafin;
    }

    public String busquedaDiccIdioma(String idioma) {

        Iterator<Diccionario> d = diccionarios.values().iterator();
        HashMap<String, Diccionario> encontrados = new HashMap();
        String cadenafin = "No hay coincidencias.";
        while (d.hasNext()) {

            Diccionario dicc = d.next();
            if (dicc.getIdioma().equals(idioma)) {
                encontrados.put(dicc.getIsbn(), dicc);
            }

        }
        Iterator<Diccionario> encontradosit = encontrados.values().iterator();
        while (encontradosit.hasNext()) {

            Diccionario dicc2 = encontradosit.next();

            cadenafin = dicc2.toStringA();

        }
        return cadenafin;
    }

    public String busquedaLectoresMarca(String marca) {

        Iterator<Lector> l = lectores.values().iterator();
        HashMap<String, Lector> encontrados = new HashMap();
        String cadenafin = "No hay coincidencias.";
        while (l.hasNext()) {

            Lector lec = l.next();
            if (lec.getMarca().equals(marca)) {
                encontrados.put(lec.getNumSerie(), lec);
            }

        }
        Iterator<Lector> encontradosit = encontrados.values().iterator();
        while (encontradosit.hasNext()) {

            Lector lector2 = encontradosit.next();

            cadenafin = lector2.toStringA();

        }
        return cadenafin;

    }

    public String busquedaAvIsbn(String isbn) {
        //PublicacionDigital fin = null;
        String cadenafin = "No hay coincidencias";
        if (libsTexto.containsKey(isbn)) {
            //LibroTexto encontrado = libsTexto.get(isbn);
            //fin = encontrado;
            cadenafin = libsTexto.get(isbn).toStringA();
        } else if (libsLectura.containsKey(isbn)) {
            //LibroLectura encontrado = libsLectura.get(isbn);
            //fin = encontrado;
            cadenafin = libsLectura.get(isbn).toStringA();
        } else if (diccionarios.containsKey(isbn)) {
            //Diccionario encontrado = diccionarios.get(isbn);
            //fin = encontrado;
            cadenafin = diccionarios.get(isbn).toStringA();
        }
        //cadenafin = fin.toStringA();
        return cadenafin;
    }

    public Lector[] busquedaAvPrecio(double precio) {

        Iterator<Lector> l = lectores.values().iterator();
        HashMap<String, Lector> encontrados = new HashMap();
        int cuantos = 0;
        //int cont=0;
        while (l.hasNext()) {

            Lector lec = l.next();
            if (lec.getPrecio() < precio) {
                encontrados.put(lec.getNumSerie(), lec);
                cuantos++;
            }
        }

        //ORDENAR
        Iterator<Lector> iterator = encontrados.values().iterator();

        Lector[] ordenados = new Lector[cuantos];
        for (int i = 0; i < cuantos; i++) {
            ordenados[i] = iterator.next();
        }
        Lector aux = null;
        for (int j = 0; j < cuantos; j++) {
            for (int t = 0; t < cuantos - j - 1; t++) {
                if (ordenados[t + 1].getPrecio() < ordenados[t].getPrecio()) {
                    aux = ordenados[t + 1];
                    ordenados[t + 1] = ordenados[t];
                    ordenados[t] = aux;
                }
            }

        }
        return ordenados;
    }

    public String busquedaAvanzada(String autor, String titulo) {

        Iterator<Diccionario> d = diccionarios.values().iterator();
        Iterator<LibroTexto> lt = libsTexto.values().iterator();
        Iterator<LibroLectura> ll = libsLectura.values().iterator();

        HashMap<String, PublicacionDigital> encontrados = new HashMap();
        String cadenafin = "No hay coincidencias.";

        while (d.hasNext()) {

            Diccionario dicc = d.next();
            if (dicc.getAutor().equals(autor) && dicc.getTitulo().equals(titulo)) {
                encontrados.put(dicc.getIsbn(), dicc);
            }

        }
        while (lt.hasNext()) {

            LibroTexto libtex = lt.next();
            if (libtex.getAutor().equals(autor) && libtex.getTitulo().equals(titulo)) {
                encontrados.put(libtex.getIsbn(), libtex);
            }

        }
        while (ll.hasNext()) {

            LibroLectura liblec = ll.next();
            if (liblec.getAutor().equals(autor) && liblec.getTitulo().equals(titulo)) {
                encontrados.put(liblec.getIsbn(), liblec);
            }

        }
        Iterator<PublicacionDigital> encontradosit = encontrados.values().iterator();
        while (encontradosit.hasNext()) {

            PublicacionDigital publi = encontradosit.next();

            cadenafin = publi.toStringA();

        }
        return cadenafin;

    }

    public String busquedaAvanzadaAutor(String autor) {

        Iterator<Diccionario> d = diccionarios.values().iterator();
        Iterator<LibroTexto> lt = libsTexto.values().iterator();
        Iterator<LibroLectura> ll = libsLectura.values().iterator();

        HashMap<String, PublicacionDigital> encontrados = new HashMap();
        String cadenafin = "No hay coincidencias.";

        while (d.hasNext()) {

            Diccionario dicc = d.next();
            if (dicc.getAutor().equals(autor)) {
                encontrados.put(dicc.getIsbn(), dicc);
            }

        }
        while (lt.hasNext()) {

            LibroTexto libtex = lt.next();
            if (libtex.getAutor().equals(autor)) {
                encontrados.put(libtex.getIsbn(), libtex);
            }

        }
        while (ll.hasNext()) {

            LibroLectura liblec = ll.next();
            if (liblec.getAutor().equals(autor)) {
                encontrados.put(liblec.getIsbn(), liblec);
            }

        }
        Iterator<PublicacionDigital> encontradosit = encontrados.values().iterator();
        while (encontradosit.hasNext()) {

            PublicacionDigital publi = encontradosit.next();

            cadenafin = publi.toStringA();

        }
        return cadenafin;

    }

    public String busquedaAvanzadaTitulo(String titulo) {

        Iterator<Diccionario> d = diccionarios.values().iterator();
        Iterator<LibroTexto> lt = libsTexto.values().iterator();
        Iterator<LibroLectura> ll = libsLectura.values().iterator();

        HashMap<String, PublicacionDigital> encontrados = new HashMap();
        String cadenafin = "No hay coincidencias.";

        while (d.hasNext()) {

            Diccionario dicc = d.next();
            if (dicc.getTitulo().equals(titulo)) {
                encontrados.put(dicc.getIsbn(), dicc);
            }

        }
        while (lt.hasNext()) {

            LibroTexto libtex = lt.next();
            if (libtex.getTitulo().equals(titulo)) {
                encontrados.put(libtex.getIsbn(), libtex);
            }

        }
        while (ll.hasNext()) {

            LibroLectura liblec = ll.next();
            if (liblec.getTitulo().equals(titulo)) {
                encontrados.put(liblec.getIsbn(), liblec);
            }

        }
        Iterator<PublicacionDigital> encontradosit = encontrados.values().iterator();
        while (encontradosit.hasNext()) {

            PublicacionDigital publi = encontradosit.next();

            cadenafin = publi.toStringA();

        }
        return cadenafin;
    }

    public String verTodo() {

        Iterator<Diccionario> d = diccionarios.values().iterator();
        Iterator<LibroTexto> lt = libsTexto.values().iterator();
        Iterator<LibroLectura> ll = libsLectura.values().iterator();
        Iterator<Lector> le = lectores.values().iterator();
        String diccs = "";
        String librostexto = "";
        String libroslectura = "";
        String lectors = "";

        while (d.hasNext()) {

            Diccionario dicc = d.next();

            diccs = diccs + dicc.toStringA();

        }
        while (lt.hasNext()) {

            LibroTexto libtex = lt.next();
            librostexto = librostexto + libtex.toStringA();

        }
        while (ll.hasNext()) {

            LibroLectura liblec = ll.next();
            libroslectura = libroslectura + liblec.toStringA();
        }
        while (le.hasNext()) {

            Lector lector = le.next();
            lectors = lectors + lector.toStringA();
        }
        return librostexto + libroslectura + diccs + lectors;

    }

    public String verTexto() {

        Iterator<LibroTexto> lt = libsTexto.values().iterator();

        String librostexto = "";

        while (lt.hasNext()) {

            LibroTexto libtex = lt.next();
            librostexto = librostexto + libtex.toStringA();

        }

        return librostexto;

    }

    public String verLectura() {

        Iterator<LibroLectura> lt = libsLectura.values().iterator();

        String libroslectura = "";

        while (lt.hasNext()) {

            LibroLectura liblec = lt.next();
            libroslectura = libroslectura + liblec.toStringA();

        }

        return libroslectura;

    }

    public String verDiccionarios() {

        Iterator<Diccionario> lt = diccionarios.values().iterator();

        String diccios = "";

        while (lt.hasNext()) {

            Diccionario dicc = lt.next();
            diccios = diccios + dicc.toStringA();

        }

        return diccios;

    }

    public String verLector() {

        Iterator<Lector> le = lectores.values().iterator();

        String lectors = "";

        while (le.hasNext()) {

            Lector lector = le.next();
            lectors = lectors + lector.toStringA();
        }
        return lectors;

    }

    //SERIALIZACIÓN
    public static void cargarDatosLector() {
        try {
            try (FileInputStream fis = new FileInputStream("Lectores.dat");
                    ObjectInputStream oislect = new ObjectInputStream(fis)) {
                lectores = (HashMap) oislect.readObject();
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.out.println("Error de clase no encontrada: " + cnfe.getMessage());
        }
    }

    public static void cargarDatosTexto() {
        try {
            try (FileInputStream fis = new FileInputStream("LibsTexto.dat");
                    ObjectInputStream oislect = new ObjectInputStream(fis)) {
                libsTexto = (HashMap) oislect.readObject();
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.out.println("Error de clase no encontrada: " + cnfe.getMessage());
        }
    }

    public static void cargarDatosLectura() {
        try {
            try (FileInputStream fis = new FileInputStream("LibsLectura.dat");
                    ObjectInputStream oislect = new ObjectInputStream(fis)) {
                libsLectura = (HashMap) oislect.readObject();
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.out.println("Error de clase no encontrada: " + cnfe.getMessage());
        }
    }

    public static void cargarDatosDicc() {
        try {
            try (FileInputStream fis = new FileInputStream("Diccionarios.dat");
                    ObjectInputStream oislect = new ObjectInputStream(fis)) {
                diccionarios = (HashMap) oislect.readObject();
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.out.println("Error de clase no encontrada: " + cnfe.getMessage());
        }
    }

    public static void cargarDatosUsers() {
        try {
            try (FileInputStream fis = new FileInputStream("Users.dat");
                    ObjectInputStream oislect = new ObjectInputStream(fis)) {
                registrados = (HashMap) oislect.readObject();
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.out.println("Error de clase no encontrada: " + cnfe.getMessage());
        }
    }

    public static void cargarDatosPass() {
        try {
            try (FileInputStream fis = new FileInputStream("Pass.dat");
                    ObjectInputStream oislect = new ObjectInputStream(fis)) {
                listaClientes = (HashMap) oislect.readObject();
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        } catch (ClassNotFoundException cnfe) {
            System.out.println("Error de clase no encontrada: " + cnfe.getMessage());
        }
    }

    public void guardarDatosLector() {
        try {
            //Si hay datos los guardamos...
            if (!lectores.isEmpty()) {
                try (
                        FileOutputStream fos = new FileOutputStream("Lectores.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos)) {

                    oos.writeObject(lectores);
                }
            } else {
                System.out.println("Error: No hay datos de lectores...");
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        }
    }

    public void guardarDatosTexto() {
        try {
            //Si hay datos los guardamos...
            if (!libsTexto.isEmpty()) {
                try (
                        FileOutputStream fos = new FileOutputStream("LibsTexto.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos)) {

                    oos.writeObject(libsTexto);
                }
            } else {
                System.out.println("Error: No hay datos de lectores...");
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        }
    }

    public void guardarDatosLectura() {
        try {
            //Si hay datos los guardamos...
            if (!libsLectura.isEmpty()) {
                try (
                        FileOutputStream fos = new FileOutputStream("LibsLectura.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos)) {

                    oos.writeObject(libsLectura);
                }
            } else {
                System.out.println("Error: No hay datos de lectores...");
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        }
    }

    public void guardarDatosDicc() {
        try {
            //Si hay datos los guardamos...
            if (!diccionarios.isEmpty()) {
                try (
                        FileOutputStream fos = new FileOutputStream("Diccionarios.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos)) {

                    oos.writeObject(diccionarios);
                }
            } else {
                System.out.println("Error: No hay datos de lectores...");
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        }
    }

    public void guardarDatosUsers() {

        try {
            //Si hay datos los guardamos...
            if (!registrados.isEmpty()) {
                try (
                        FileOutputStream fos = new FileOutputStream("Users.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos)) {

                    oos.writeObject(registrados);
                }
            } else {
                System.out.println("Error: No hay datos de lectores...");
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        }
    }

    public void guardarDatosPass() {
        try {
            //Si hay datos los guardamos...
            if (!listaClientes.isEmpty()) {
                try (
                        FileOutputStream fos = new FileOutputStream("Pass.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos)) {

                    oos.writeObject(listaClientes);
                }
            } else {
                System.out.println("Error: No hay datos de lectores...");
            }

        } catch (IOException ioe) {
            System.out.println("Error de IO: " + ioe.getMessage());
        }
    }

    //GENERAR TICKETS
    public void generarTicketLibro() {

        File f;
        FileWriter w;
        BufferedWriter bw;
        PrintWriter wr;
        Date date1 = new Date();

        try {
            f = new File(clienteiniciado.getNombre() + date1.getTime() + ".txt");
            w = new FileWriter(f);
            bw = new BufferedWriter(w);
            wr = new PrintWriter(bw);

            wr.write("El usuario" + clienteiniciado.getNombre() + " ha comprado una publicación digital:" + librocomprado.getTitulo() + 
                    "\r\nISBN: " + librocomprado.getIsbn() +
                    "\r\nFormato: "+formatodescarga+ 
                    "\r\nPRECIO: " + preciotrasdescuento + "€."
                    + "\r\nPagado con la tarjeta de crédito " + numerotarjeta);
            wr.close();

        } catch (Exception e) {
            System.out.println("Se ha producido un error:" + e);
        }

    }

    public void generarTicketLector() {

        File f;
        FileWriter w;
        BufferedWriter bw;
        PrintWriter wr;
        Date date1 = new Date();

        try {
            f = new File(clienteiniciado.getNombre() + date1.getTime() + ".txt");
            w = new FileWriter(f);
            bw = new BufferedWriter(w);
            wr = new PrintWriter(bw);

            wr.write("El usuario " + clienteiniciado.getNombre() + " ha comprado el lector: " 
                    + lectorcomprado.getMarca() + ""
                    + "\r\nModelo:" + lectorcomprado.getModelo() 
                    + "\r\nNumero de serie: " + lectorcomprado.getNumSerie() + 
                    "\r\nPRECIO: " + lectorcomprado.getPrecio() + "€."
                    + "\r\nPagado con la tarjeta de crédito " + numerotarjeta + 
                    "\r\nSe enviará a la dirección " + direccion);
            wr.close();

        } catch (Exception e) {
            System.out.println("Se ha producido un error:" + e);
        }

    }

    public void generarTicketConsulta() {

        File f;
        FileWriter w;
        BufferedWriter bw;
        PrintWriter wr;
        Date date1 = new Date();

        try {
            f = new File(clienteiniciado.getNombre() + date1.getTime() + ".txt");
            w = new FileWriter(f);
            bw = new BufferedWriter(w);
            wr = new PrintWriter(bw);

            wr.write("El usuario" + clienteiniciado.getNombre() + " podrá consultar online el libro ``" + librocomprado.getTitulo() + 
                    "\r\nISBN " + librocomprado.getIsbn() + 
                    "\r\nMeses consulta: " + mesesconsulta + 
                    "\r\nPRECIO" + preciotrasdescuento + "€."
                    + "\r\nPagado con la tarjeta de crédito " + numerotarjeta);
            wr.close();

        } catch (Exception e) {
            System.out.println("Se ha producido un error:" + e);
        }

    }

}
