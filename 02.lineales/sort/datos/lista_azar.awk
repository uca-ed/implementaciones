# Imprime una cantidad de números al azar según indicado por el argumento cantidad.
#
# Modo de uso: 
# awk -f lista_azar.awk -v cantidad=50000

BEGIN {
 if (!cantidad) {
    cantidad=10000;
 }
 for (i=0; i<cantidad; i++) {
   print int(rand()*10000)
 }
}
