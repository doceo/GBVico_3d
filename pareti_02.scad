
spessore=5; //da decidere se uguale per tutte oppure no
altezza=50; //uguale per tutte le pareti
lunghezza_uno=73; //lunghezza della prima parete
lunghezza_due = 97; //lunghezza della seconda parete

// la distanza della porta deve essere considerata in  relazione all'angolo tra le pareti
altezza_porta = 20; 
larghezza_porta = 12;
distanza_porta = 46;

//parametri relativi alle finestre
lunghezza_fin=15;
 altezza_fin=11;

due_pareti_porta();

module due_pareti(){
   
    cube([lunghezza_due, spessore, altezza]);
   rotate([0,0,90])    cube([lunghezza_uno, spessore, altezza]);
    
}


module due_pareti_porta(){
    
    difference(){
        due_pareti();
        translate([-spessore,distanza_porta+spessore,0]) cube([spessore,larghezza_porta,altezza_porta]);
    }
}

module finestra(){
    
    cube([lunghezza_fin, spessore, altezza_fin]);
    
    }
    
    
    