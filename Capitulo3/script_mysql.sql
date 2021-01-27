-- -----------------------------------------------------
-- Table mydb.GRUPO
-- -----------------------------------------------------
CREATE TABLE GRUPO(
  codigo_grupo INT NOT NULL,
  nombre TEXT NULL,
  genero_musical TEXT NULL,
  pais TEXT NULL,
  sitio_web TEXT NULL,
  PRIMARY KEY (codigo_grupo))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table mydb.MUSICOS
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS mydb.MUSICOS (
  codigo_musico INT NOT NULL,
  dni VARCHAR(10) NOT NULL,
  nombre TEXT NULL,
  direccion TEXT NULL,
  codigo_postal INT NULL,
  ciudad TEXT NULL,
  provincia TEXT NULL,
  telefono INT NULL,
  instrumentos TEXT NULL,
  GRUPO_codigo_grupo INT NOT NULL,
  PRIMARY KEY (codigo_musico),
  UNIQUE INDEX dni_UNIQUE (dni ASC) VISIBLE,
  INDEX fk_MUSICOS_GRUPO1_idx (GRUPO_codigo_grupo ASC) VISIBLE,
  CONSTRAINT fk_MUSICOS_GRUPO1
    FOREIGN KEY (GRUPO_codigo_grupo)
    REFERENCES mydb.GRUPO (codigo_grupo)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table mydb.DISCOS
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS mydb.DISCOS (
  codigo_disco INT NOT NULL,
  titulo TEXT NULL,
  fecha_edicion DATE NULL,
  genero TEXT NULL,
  formato TEXT NULL,
  GRUPO_codigo_grupo INT NOT NULL,
  PRIMARY KEY (codigo_disco),
  INDEX fk_DISCOS_GRUPO1_idx (GRUPO_codigo_grupo ASC) VISIBLE,
  CONSTRAINT fk_DISCOS_GRUPO1
    FOREIGN KEY (GRUPO_codigo_grupo)
    REFERENCES mydb.GRUPO (codigo_grupo)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table mydb.CANCIONES
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS mydb.CANCIONES (
  codigo_cancion INT NOT NULL,
  nombre TEXT NULL,
  compositor TEXT NULL,
  fecha_grabacion DATE NULL,
  duracion TIME NULL,
  DISCOS_codigo_disco INT NOT NULL,
  PRIMARY KEY (codigo_cancion),
  INDEX fk_CANCIONES_DISCOS1_idx (DISCOS_codigo_disco ASC) VISIBLE,
  CONSTRAINT fk_CANCIONES_DISCOS1
    FOREIGN KEY (DISCOS_codigo_disco)
    REFERENCES mydb.DISCOS (codigo_disco)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table mydb.CONCIERTOS
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS mydb.CONCIERTOS (
  codigo_concierto INT NOT NULL,
  fecha_realizacion DATE NULL,
  pais TEXT NULL,
  ciudad TEXT NULL,
  recinto TEXT NULL,
  PRIMARY KEY (codigo_concierto))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table mydb.ENTRADAS
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS mydb.ENTRADAS (
  codigo_entrada INT NOT NULL,
  localidad TEXT NULL,
  precio INT NULL,
  usuario TEXT NULL,
  CONCIERTOS_codigo_concierto INT NOT NULL,
  PRIMARY KEY (codigo_entrada),
  INDEX fk_ENTRADAS_CONCIERTOS_idx (CONCIERTOS_codigo_concierto ASC) VISIBLE,
  CONSTRAINT fk_ENTRADAS_CONCIERTOS
    FOREIGN KEY (CONCIERTOS_codigo_concierto)
    REFERENCES mydb.CONCIERTOS (codigo_concierto)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table mydb.GRUPO_has_CONCIERTOS
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS mydb.GRUPO_has_CONCIERTOS (
  GRUPO_codigo_grupo INT NOT NULL,
  CONCIERTOS_codigo_concierto INT NOT NULL,
  PRIMARY KEY (GRUPO_codigo_grupo, CONCIERTOS_codigo_concierto),
  INDEX fk_GRUPO_has_CONCIERTOS_CONCIERTOS1_idx (CONCIERTOS_codigo_concierto ASC) VISIBLE,
  INDEX fk_GRUPO_has_CONCIERTOS_GRUPO1_idx (GRUPO_codigo_grupo ASC) VISIBLE,
  CONSTRAINT fk_GRUPO_has_CONCIERTOS_GRUPO1
    FOREIGN KEY (GRUPO_codigo_grupo)
    REFERENCES mydb.GRUPO (codigo_grupo)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_GRUPO_has_CONCIERTOS_CONCIERTOS1
    FOREIGN KEY (CONCIERTOS_codigo_concierto)
    REFERENCES mydb.CONCIERTOS (codigo_concierto)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
