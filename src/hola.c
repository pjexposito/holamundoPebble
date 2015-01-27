    #include <pebble.h> //Librería principal
      
      
 static Window *window;  //Se crea en memoria la ventana principal
 static TextLayer *text_layer; //En esa ventana, se añaden capas de texto


static void init() {  //Función de inicialización
  window = window_create(); //Se crea la ventana
  window_stack_push(window, true /* Animated */);  //Y se pone sobre el resto
  window_set_background_color(window, GColorBlack);  //Pintamos la ventana de negro
  char *DATO = "Hola";
  
  Layer *window_layer = window_get_root_layer(window);  //Es la capa más baja de la aplicación, donde se pintaría el fondo
  

  
  GRect bounds = layer_get_frame(window_layer); //Se encarga de conseguir el tamaño de la ventana
  text_layer = text_layer_create((GRect){ .origin = { 0, 0 }, .size = bounds.size });  //Se reserva en memoria espacio para una capa
  //text_layer = text_layer_create(UPPER_TO_RECT);
 

  text_layer_set_text(text_layer, DATO);  //Estilo de texto
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT)); //Fuente
  //text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);  //Alineación
  //text_layer_set_text_color(text_layer, GColorWhite);
  //text_layer_set_background_color(text_layer, GColorBlack);

  layer_add_child(window_layer, text_layer_get_layer(text_layer));  //Añade la capa anterior como hijo de la principal LAYER
  
}

static void deinit() {  //Función para desinicializar la aplicación. Destruye de memoria la
  text_layer_destroy(text_layer);  //Capa de texto
  window_destroy(window);  //La ventana
}


int main(void) {  
  init();  //Inicia
  app_event_loop();  //Espera evento
  deinit();  //Mata
}
