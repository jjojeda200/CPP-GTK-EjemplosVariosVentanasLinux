/***************************************************************************************
    José Juan Ojeda Granados
    Fecha:        20-11-2022
    Titulo:       00IntroGTK.hpp
    Descripción:  Practicas con GTK
    
    https://docs.gtk.org/gtk3/index.html              Fudamentales
    https://www.manpagez.com/html/gtk3/gtk3-3.24.31/       "
    https://lazka.github.io/pgi-docs/Gtk-3.0/index.html    "

    https://runebook.dev/es/docs/gtk/-index-
    https://gnome.pages.gitlab.gnome.org/gtk/gtk3/index.html
    https://es.gnome.org/Documentacion/Desarrollo/Gtk

      Compilar desde terminal con:
      gcc GTK-Practica01.cpp `pkg-config --cflags --libs gtk+-3.0` -o GTK-Practica01

***************************************************************************************/
#include <gtk/gtk.h>

const char *Titulo;
int Ancho, Alto;

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

void imprime()
{
      printf("Ancho %d, Alto %d \n", Ancho, Alto);
}

static void EntradaTexto(GtkWidget *widget, gpointer dato)
{
      g_print("EnTexto = %s \n", gtk_entry_get_text((GTK_ENTRY(dato))));
      // gtk_entry_set_text(GTK_ENTRY(dato),"Texto OK");

      gtk_editable_select_region(GTK_EDITABLE(dato), 2, -1);
      gtk_editable_copy_clipboard(GTK_EDITABLE(dato));
}

void Etiqueta(GtkWidget *widget, gpointer texto00)
{
      // g_print("Hola Claudia\n");

      gtk_label_set_text(GTK_LABEL(widget), (char*) "Hola Prudencia");

      //gtk_widget_hide(widget);
}

static void radio_func(GtkWidget *widget, gpointer dato)
{    if(strcmp((char*)dato, "1") == 0)
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            g_print("Botón %s ahora activo\n", (char*)dato);
        else
            g_print("Botón %s ahora desactivo\n", (char*)dato);

    if(strcmp((char*)dato, "2") == 0)
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            g_print("Botón %s ahora activo\n", (char*)dato);
        else
            g_print("Botón %s ahora desactivo\n", (char*)dato);

    if(strcmp((char*)dato, "3") == 0)
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
            g_print("Botón %s ahora activo\n", (char*)dato);
        else
            g_print("Botón %s ahora desactivo\n", (char*)dato);

}

static gboolean inc_progreso(gpointer dato)
{
      static float porcentaje = 0.0;
      bool fin = true;
      porcentaje += 0.05;
      if (porcentaje > 1.0)
      {
        fin = false;
        porcentaje = 0.0;
      }
      gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(dato), porcentaje);

      char c[3];
      sprintf(c, "%d%%", static_cast<int>(porcentaje * 100));
      gtk_progress_bar_set_text(GTK_PROGRESS_BAR(dato), c);

      return fin;
}

static void activate(GtkApplication *Practica, gpointer user_data)
{
      // GtkWidget declara el tipo de objetos widgets
      // Crea una ventana principal y adjunta devoluciones de llamada de señal.
      GtkWidget *ventana0 = gtk_application_window_new(Practica);
      GtkWidget *caja00 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
      GtkWidget *caja01 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
      GtkWidget *texto00 = gtk_label_new("José Juan Ojeda Granados, 20-11-2022\nEmpecemos con GTK\n");
      GtkWidget *boton00 = gtk_button_new_with_mnemonic("Salir");
      // GtkWidget *boton01 = gtk_button_new_with_label("Aux");
      GtkWidget *boton01 = gtk_button_new(); 
      GtkWidget *boton02 = gtk_button_new_with_label("Texto");
      GtkWidget *imagen00 = gtk_image_new_from_file ("./imagenes/Compartir.png");
      GtkWidget *imagen01 = gtk_image_new_from_file ("./imagenes/Bel.jpg");
      gtk_button_set_image(GTK_BUTTON(boton01), imagen00);
      // gtk_button_set_relief(GTK_BUTTON(boton00), GTK_RELIEF_NONE);

      GtkWidget *window1;
      GtkWidget *caja10;
      GtkWidget *caja11;
      GtkWidget *caja12;
      GtkWidget *boton10;
      GtkWidget *boton11;
      GtkWidget *texto10;
      GtkWidget *texto11;
      GtkWidget *texto12;
      GtkWidget *window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      // GtkWidget *window2 = gtk_window_new(GTK_WINDOW_POPUP);

      //*******************************************************************
      GtkWidget *EnTexto = gtk_entry_new();
      
      // Estructura struct GtkEntryBuffer 
      GtkEntryBuffer *Buf00;
      // Crea un nuevo objeto (buffer) GtkEntryBuffer, Ojo con los datos
      Buf00 = gtk_entry_buffer_new("Contenido Buf00", -1);
                                    // -1 O longitud exacta del contenido
      Buf00 = gtk_entry_buffer_new("Contenido Buf00", 15);
      gtk_entry_buffer_set_max_length(Buf00, 50);
      // Crea la primera entrada
      EnTexto = gtk_entry_new_with_buffer (Buf00);
      printf("Longitud Buf00 %d \n",gtk_entry_buffer_get_length(Buf00));
      printf("Longitud max. Buf00 %d \n",gtk_entry_buffer_get_max_length(Buf00));

      printf("Texto en Buf00 %s \n",gtk_entry_buffer_get_text(Buf00));

      //*******************************************************************
      // Establecer títulos de ventanas
      gtk_window_set_title(GTK_WINDOW(ventana0), "Ventana de aplicación"); 
      gtk_window_set_title(GTK_WINDOW(window2), "Ventana 2");
      /*
      La posición de la ventana de configuración en la pantalla está centrada.
        * GTK_WIN_POS_NONE: no fijo
        * GTK_WIN_POS_CENTER: centrado
        * GTK_WIN_POS_MOUSE: aparece en la posición del mouse
        * GTK_WIN_POS_CENTER_ALWAYS: la ventana permanece centrada si se cambia de tamaño
      */
      gtk_window_move(GTK_WINDOW(ventana0), 1000, 800);            // Mueve la ventana a la posición
      gtk_window_set_position(GTK_WINDOW(ventana0), GTK_WIN_POS_CENTER);
      gtk_window_set_default_size(GTK_WINDOW(ventana0), 100, 100); // Establece el tamaño predeterminado de la ventana
      gtk_window_set_resizable(GTK_WINDOW(ventana0), FALSE);       // Redimencionar tamaño True/False
      // Muestra/Oculta componentes de ventana (menu, bordes, etc.) Por defecto TRUE
      gtk_window_set_decorated(GTK_WINDOW(ventana0), TRUE); 

      gtk_widget_set_tooltip_text(boton00, "Botón Salir");
      gtk_widget_set_margin_bottom(boton00, 60);
      gtk_widget_set_margin_top(boton00, 60);
      gtk_widget_set_margin_bottom(boton01, 60);
      gtk_widget_set_margin_top(boton01, 60);
      gtk_widget_set_margin_bottom(boton02, 60);
      gtk_widget_set_margin_top(boton02, 60);

      // Establece el tamaños del widget
      gtk_widget_set_size_request(boton01, 180, 180);
      gtk_widget_set_size_request(boton02, 180, 180);
      gtk_widget_set_size_request(texto00, 80, 80);
      // gtk_widget_get_size_request(boton01, &Ancho, &Alto);
      // printf("widget boton01: Ancho %d, Alto %d \n", Ancho, Alto);

      gtk_container_add(GTK_CONTAINER(ventana0), caja00);
      // La ventana ya es un contenedor, pero solo puede contener un widget
      // gtk_container_remove(GTK_CONTAINER(ventana0), caja00);
      // gtk_container_add(GTK_CONTAINER(ventana0), boton00);
      // Establece el ancho del borde de la ventana
      gtk_container_set_border_width(GTK_CONTAINER(ventana0), 10);
      gtk_container_set_border_width(GTK_CONTAINER(window2), 10);
      gtk_box_pack_start(GTK_BOX(caja00), caja01, TRUE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(caja01), texto00, TRUE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(caja00), EnTexto, false, false, 0);
      gtk_box_pack_start(GTK_BOX(caja00), boton00, FALSE, FALSE, 0);
      gtk_box_pack_end(GTK_BOX(caja01), boton01, FALSE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(caja01), boton02, FALSE, FALSE, 0);

      //*******************************************************************
      GtkWidget *caja20 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
      GtkWidget *altOnOff00 = gtk_toggle_button_new_with_mnemonic("On/Off 0_0");
      GtkWidget *altOnOff01 = gtk_check_button_new_with_mnemonic("On/Off 0_1");

      gtk_container_set_border_width(GTK_CONTAINER(window2), 10);
      gtk_container_add(GTK_CONTAINER(window2), caja20);
      gtk_box_pack_start(GTK_BOX(caja20), altOnOff00, false, false, 0);
      gtk_box_pack_start(GTK_BOX(caja20), altOnOff01, false, false, 0);
      gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(altOnOff00), true);

      //*******************************************************************
      // https://lazka.github.io/pgi-docs/Gtk-3.0/classes/RadioButton.html#example
      GtkWidget *radio00 = gtk_radio_button_new_with_mnemonic(NULL, "Etiqueta _0");
      GtkWidget *radio01 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio00), "Etiqueta 1");
      GtkWidget *radio02 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio00), "Etiqueta 3");
      gtk_box_pack_start(GTK_BOX(caja20), radio00, false, false, 0);
      gtk_box_pack_start(GTK_BOX(caja20), radio01, false, false, 0);
      gtk_box_pack_start(GTK_BOX(caja20), radio02, false, false, 0);
      // g_signal_connect(GTK_RADIO_BUTTON(radio00), "toggled", G_CALLBACK(radio_func), (gpointer)"1");
      g_signal_connect(radio00, "toggled", G_CALLBACK(radio_func), (gpointer)"1");
      g_signal_connect(radio01, "toggled", G_CALLBACK(radio_func), (gpointer)"2");
      g_signal_connect(radio02, "toggled", G_CALLBACK(radio_func), (gpointer)"3");

      //*******************************************************************
      GtkWidget *progreso = gtk_progress_bar_new();
      // gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progreso), 0.01);
      // gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progreso), "50%"); 

      gtk_progress_bar_set_show_text (GTK_PROGRESS_BAR(progreso), true);
      g_timeout_add(500, inc_progreso, progreso);     // 300 ms

      gtk_box_pack_end(GTK_BOX(caja01), progreso, FALSE, FALSE, 0);


      //*******************************************************************

      /*
      Esto hará que la ventana sea destruida al llamar a gtk_widget_destroy (ventana) cuando "haga clic". Una vez más, la señal de destrucción podría provenir de aquí o del administrador de ventanas.
      */
      g_signal_connect_swapped(G_OBJECT(boton00), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(ventana0));

      //*******************************************************************
      g_signal_connect (G_OBJECT(boton01), "clicked", G_CALLBACK (imprime), NULL);

      g_signal_connect_swapped(G_OBJECT(boton01), "clicked", G_CALLBACK (gtk_widget_destroy),G_OBJECT (window2));

      g_signal_connect_swapped (G_OBJECT(boton01), "pressed", G_CALLBACK(gtk_widget_hide), G_OBJECT(texto00));
      g_signal_connect_swapped(G_OBJECT(boton01), "clicked", G_CALLBACK(Etiqueta), texto00);
      g_signal_connect_swapped (G_OBJECT(boton01), "released", G_CALLBACK(gtk_widget_show), G_OBJECT(texto00));
      
      g_signal_connect_swapped(G_OBJECT(boton01), "clicked", G_CALLBACK (gtk_widget_hide),G_OBJECT (boton01));

      g_signal_connect(boton02, "clicked", G_CALLBACK(EntradaTexto), EnTexto);
      // Presionando intro llamada ala función
      g_signal_connect(EnTexto, "activate", G_CALLBACK(EntradaTexto), EnTexto);
      //*******************************************************************

      /*
      La función gtk_window_set_icon () se usa para configurar el icono de la ventana, y la función create_pixbuf es personalizada por nosotros, con el propósito de obtener el pixbuf de una imagen.
      */
      gtk_window_set_icon(GTK_WINDOW(ventana0), create_pixbuf("./imagenes/AgujaBrujula.png"));

      /*
      Aquí se genera un componente de ventana: GtkWindow, GTK_WINDOW_TOPLEVEL contiene la barra de título y el borde de la ventana, y se acuerda usar el administrador de ventanas para administrarlo
      */
      window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      gtk_window_set_title(GTK_WINDOW(window1), "Ventana 1");
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
      gtk_box_pack_start(GTK_BOX(caja10), imagen01, false, false, 0);
      gtk_box_pack_start(GTK_BOX(caja10), caja11, FALSE, FALSE, 50);
      gtk_box_pack_start(GTK_BOX(caja10), caja12, TRUE, FALSE, 50);
      gtk_box_pack_start(GTK_BOX(caja11), boton10, TRUE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(caja11), boton11, TRUE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(caja12), texto10, TRUE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(caja12), texto11, TRUE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(caja12), texto12, TRUE, FALSE, 0);

      g_signal_connect_swapped(G_OBJECT(boton10), "clicked", G_CALLBACK(gtk_widget_hide), G_OBJECT(texto12));
      g_signal_connect_swapped(G_OBJECT(boton11), "clicked", G_CALLBACK(gtk_widget_show), G_OBJECT(texto12));


      gtk_widget_show_all(ventana0);
      // gtk_widget_show(window);
      // gtk_widget_show(button);
      gtk_widget_show_all(window1);
      gtk_widget_show_all(window2);


      //*******************************************************************
      // Getter
      // La conversión siguiente no es necesaria al definir Titulo como const
      // Titulo = (char*)gtk_window_get_title(GTK_WINDOW(ventana0));
      Titulo = gtk_window_get_title(GTK_WINDOW(ventana0));
      printf("Titulo es: %s \n", Titulo);

      gtk_window_get_size(GTK_WINDOW(ventana0), &Ancho, &Alto);
      printf("Ancho %d, Alto %d \n", Ancho, Alto);

      printf("Se puede redimensionar %d \n", gtk_window_get_resizable(GTK_WINDOW(ventana0)));
      printf("Se puede enfocar %d \n", gtk_window_get_accept_focus(GTK_WINDOW(ventana0)));
      printf("Esta activa %d \n", gtk_window_is_active(GTK_WINDOW(ventana0)));
}

int main(int argc, char **argv)
{
      // Se llama en todas las aplicaciones GTK. Los argumentos se analizan desde
      // la línea de comandos y se devuelven a la aplicación.
      gtk_init(&argc, &argv);

      // Declaración de la aplicación dándole un nombre y definiendo los flags
      GtkApplication *Practica;
      Practica = gtk_application_new("org.gtk.windowsJJOG", G_APPLICATION_FLAGS_NONE);

      // Señal que conecta la aplicación llamando a la función
      g_signal_connect(Practica, "activate", G_CALLBACK(activate), NULL);

      // Ejecución de la aplicación llamando a la función
      int status;       // Variable para almacenar resultado de la llamada
      status = g_application_run(G_APPLICATION(Practica), argc, argv);

      // Finalizar borrando la referencia ala aplicación
      g_object_unref(Practica);

      return status;
}
