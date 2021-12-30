/*
    José Juan Ojeda Granados, 27-12-2021
    Empecemos con GTK

    https://docs.gtk.org/gtk3/index.html  Fudamental

    https://gnome.pages.gitlab.gnome.org/gtk/gtk3/index.html

Compilar desde terminal con:
gcc windows.cpp `pkg-config --cflags --libs gtk+-3.0` -o windows
*/
#include <gtk/gtk.h>

GdkPixbuf *create_pixbuf(const gchar *filename)
{
  /*
  @Descripción: obtener información de una imagen para pixbuf
  @param:       gchar filename
  */
  GdkPixbuf *pixbuf;
  GError *error = NULL;
  /*
   * La función gdk_pixbuf_new_from_file() carga datos de imagen de un archivo de imagen para generar un nuevo pixbuf.
   * En cuanto al formato de la imagen contenida en el archivo, el sistema lo detecta automáticamente. Si el valor de retorno de esta función es NULL, se producirá un error en el programa.
   */
  pixbuf = gdk_pixbuf_new_from_file(filename, &error);

  if (!pixbuf)
  {
    fprintf(stderr, "%s\n", error->message);
    g_error_free(error);
  }

  return pixbuf;
}

/* Esta es una función de devolución de llamada. Los argumentos de datos se ignoran en este ejemplo. Más sobre devoluciones de llamada a continuación. */
void hello( GtkWidget *widget, gpointer texto00 )
{
  g_print ("Hola Claudia\n");
}

static void activate(GtkApplication *Practica, gpointer user_data)
{
  // GtkWidget declara el tipo de objetos widgets
  GtkWidget *ventana0 = gtk_application_window_new(Practica);     // Declara Widget y crear la ventana principal
  GtkWidget *caja00 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  GtkWidget *caja01 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  GtkWidget *texto00 = gtk_label_new("José Juan Ojeda Granados, 27-12-2021\nEmpecemos con GTK\n");
  GtkWidget *boton00 = gtk_button_new_with_mnemonic("Salir");
  GtkWidget *boton01 = gtk_button_new_with_label("Aux");
  GtkWidget *window1;
  GtkWidget *caja10;
  GtkWidget *caja11;
  GtkWidget *caja12;
  GtkWidget *boton10;
  GtkWidget *boton11;
  GtkWidget *texto10;
  GtkWidget *texto11;
  GtkWidget *texto12;
  GtkWidget *window2;

  
  gtk_window_set_title(GTK_WINDOW(ventana0), "Aplicación Windows"); // Establecer título de ventana
  /*
  La posición de la ventana de configuración en la pantalla está centrada.
    * GTK_WIN_POS_NONE: no fijo
    * GTK_WIN_POS_CENTER: centrado
    * GTK_WIN_POS_MOUSE: aparece en la posición del mouse
    * GTK_WIN_POS_CENTER_ALWAYS: la ventana permanece centrada si se cambia de tamaño
  */
  gtk_window_set_position(GTK_WINDOW(ventana0), GTK_WIN_POS_CENTER);
  gtk_window_move(GTK_WINDOW(ventana0), 0, 0);                 // Mueve la ventana a la posición
  gtk_window_set_default_size(GTK_WINDOW(ventana0), 100, 100); // Establece el tamaño predeterminado de la ventana
  gtk_window_set_resizable(GTK_WINDOW(ventana0), FALSE);       // Redimencionar tamaño True/False
  gtk_container_set_border_width(GTK_CONTAINER(ventana0), 10); // Establece el ancho del borde de la ventana

  gtk_widget_set_tooltip_text(boton00, "Boton Salir");
  gtk_widget_set_margin_bottom(boton00, 60);
  gtk_widget_set_margin_top(boton00, 60);
  gtk_widget_set_margin_bottom(boton01, 60);
  gtk_widget_set_margin_top(boton01, 60);

  gtk_container_add(GTK_CONTAINER(ventana0), caja00);
  gtk_box_pack_start(GTK_BOX (caja00), caja01, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX (caja01), texto00, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX (caja00), boton00, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX (caja00), boton01, FALSE, FALSE, 0);

  /*
  Esto hará que la ventana sea destruida al llamar a gtk_widget_destroy (ventana) cuando "haga clic". Una vez más, la señal de destrucción podría provenir de aquí o del administrador de ventanas.
  */
  g_signal_connect_swapped(G_OBJECT(boton00), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(ventana0));
  
  // g_signal_connect(G_OBJECT(boton01), "clicked", G_CALLBACK(hello), NULL);
  // Anular las dos siguientes para que la anterior funcione
  g_signal_connect_swapped(G_OBJECT(boton01), "pressed", G_CALLBACK(gtk_widget_hide), G_OBJECT(texto00));
  g_signal_connect_swapped(G_OBJECT(boton01), "released", G_CALLBACK(gtk_widget_show), G_OBJECT(texto00));

  /*
  La función gtk_window_set_icon () se usa para configurar el icono de la ventana, y la función create_pixbuf es personalizada por nosotros, con el propósito de obtener el pixbuf de una imagen.
  */
  gtk_window_set_icon(GTK_WINDOW(ventana0), create_pixbuf("./imagenes/AgujaBrujula.png"));

  /*
  Aquí se genera un componente de ventana: GtkWindow, GTK_WINDOW_TOPLEVEL contiene la barra de título y el borde de la ventana, y se acuerda usar el administrador de ventanas para administrarlo
  */
  window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window1), "TOPLEVEL");
  gtk_window_move(GTK_WINDOW(window1), 200, 200);
  gtk_window_set_default_size(GTK_WINDOW(window1), 400, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window1), 10);

  caja10 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  caja11 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
  caja12 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 100);
  texto10 = gtk_label_new("Texto 1");
  texto11 = gtk_label_new("Texto 2");
  texto12 = gtk_label_new("Texto 3");
  boton10 = gtk_button_new_with_mnemonic("Oculta");
  boton11 = gtk_button_new_with_mnemonic("Muestra");
  gtk_container_add(GTK_CONTAINER(window1), caja10);
  gtk_box_pack_start(GTK_BOX (caja10), caja11, FALSE, FALSE, 50);
  gtk_box_pack_start(GTK_BOX (caja10), caja12, TRUE, FALSE, 50);
  gtk_box_pack_start(GTK_BOX (caja11), boton10, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX (caja11), boton11, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX (caja12), texto10, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX (caja12), texto11, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX (caja12), texto12, TRUE, FALSE, 0);


  g_signal_connect_swapped(G_OBJECT(boton10), "clicked", G_CALLBACK(gtk_widget_hide), G_OBJECT(texto12));
  g_signal_connect_swapped(G_OBJECT(boton11), "clicked", G_CALLBACK(gtk_widget_show), G_OBJECT(texto12));

  window2 = gtk_window_new(GTK_WINDOW_POPUP);

  gtk_widget_show_all(ventana0);
  // gtk_widget_show(window);
  // gtk_widget_show(button);
  gtk_widget_show_all(window1);
  // gtk_widget_show(window2);

}

int main(int argc, char **argv)
{
  /*
  Esto se llama en todas las aplicaciones GTK. Los argumentos se analizan desde la línea de comandos y se devuelven a la aplicación.
  */
  gtk_init(&argc, &argv);

  GtkApplication *Practica;
  int status;

  Practica = gtk_application_new("org.gtk.windowsJJOG", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(Practica, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(Practica), argc, argv);
  g_object_unref(Practica);

  return status;
}
