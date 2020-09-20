
import java.io.Serializable;

public class Cliente implements Serializable{

    private String nombre, nif, correo, password;
    private Boolean profesor;

    public Cliente(String nombre, String nif, String correo, String password, boolean profesor) {
        this.nombre = nombre;
        this.nif = nif;
        this.correo = correo;
        this.password = password;
        this.profesor=profesor;
    }
    

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getNif() {
        return nif;
    }

    public void setNif(String nif) {
        this.nif = nif;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public Boolean getProfesor() {
        return profesor;
    }

    public void setProfesor(Boolean profesor) {
        this.profesor = profesor;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

}
