cat << 'ESOSOFTWARE' > scheduler_discovery.sh
#!/bin/bash

# ============================================================
# Practica: Exploracion del Scheduler Real en Linux (Ubuntu 22.04)
# Archivo: scheduler_discovery.sh
# Autor: Sosa Gomez David
#
# Objetivo:
# Localizar y mostrar el codigo fuente del scheduler real de Linux,
# especificamente el Completely Fair Scheduler (CFS).
# ============================================================


# ------------------------------------------------------------
# Paso 1: Informacion contextual
# ------------------------------------------------------------
echo "============================================================"
echo "Exploracion del Scheduler Real de Linux (CFS)"
echo "Sistema: $(uname -s) $(uname -r)"
echo "============================================================"
echo
echo "Se buscara el codigo fuente del scheduler del kernel Linux."
echo "El scheduler por defecto es el Completely Fair Scheduler (CFS)."
echo


# ------------------------------------------------------------
# Paso 2: Ubicacion del codigo fuente del kernel
# ------------------------------------------------------------
# El codigo fuente del kernel NO se encuentra en /home.
# Normalmente esta en /usr/src/

echo "Ubicacion actual de inicio:"
pwd
echo

echo "Listando contenido de /usr/src para localizar el kernel:"
ls -d /usr/src/linux-* 2>/dev/null
echo


# ------------------------------------------------------------
# Paso 3: Navegacion hacia el codigo del kernel
# ------------------------------------------------------------
# Intentamos entrar a linux-source (donde vive el .c)
# Si no, entramos a headers (donde viven los .h)

cd /usr/src

# Truco para que el cd no falle si hay muchas carpetas
DIR_KERNEL=$(ls -d linux-source-* 2>/dev/null | head -n 1)

if [ -z "$DIR_KERNEL" ]; then
    # Si no hay source, intentamos headers
    DIR_KERNEL=$(ls -d linux-headers-* 2>/dev/null | head -n 1)
    echo "[ADVERTENCIA] Solo se encontraron headers. Es posible que falte el paquete linux-source."
fi

echo "Entrando al directorio detectado: $DIR_KERNEL"
cd "$DIR_KERNEL"
echo

echo "Ruta actual:"
pwd
echo


# ------------------------------------------------------------
# Paso 4: Localizacion del directorio de scheduling
# ------------------------------------------------------------
# Dentro del kernel, la planificacion de procesos se encuentra
# en el directorio 'kernel/sched'.

echo "Entrando al directorio kernel/sched..."
# Nota: En headers a veces la estructura cambia, forzamos la busqueda
if [ -d "kernel/sched" ]; then
    cd kernel/sched
elif [ -d "include/linux/sched" ]; then
    cd include/linux/sched
    echo "Nota: Navegando en estructura de headers."
else
    # Fallback 
    cd kernel 2>/dev/null
fi

echo "Ruta actual:"
pwd
echo


# ------------------------------------------------------------
# Paso 5: Localizacion del scheduler principal
# ------------------------------------------------------------
# El archivo principal del Completely Fair Scheduler es: fair.c
# Este archivo implementa la logica principal del CFS.

echo "Verificando existencia de fair.c..."
ls fair.c 2>/dev/null
echo


# ------------------------------------------------------------
# Paso 6: Mostrar el codigo fuente real del scheduler
# ------------------------------------------------------------
# A continuacion se muestra el codigo fuente real del scheduler.
# Se muestran las primeras 50 lineas para evidencia.

echo "============================================================"
echo "Mostrando el codigo fuente del CFS (fair.c)"
echo "============================================================"
echo

if [ -f "fair.c" ]; then
    # Usamos head para no saturar la pantalla
    cat fair.c | head -n 50
    echo
    echo "... [Codigo truncado para legibilidad del reporte] ..."
else
    echo "ERROR: No se encontro el archivo fair.c."
    echo "Causa probable: Estas en una carpeta de 'headers' y no de 'source'."
    echo "Solucion: Instalar fuentes con 'sudo apt install linux-source'"
fi
echo


# ------------------------------------------------------------
# Reflexion final (obligatoria)
# ------------------------------------------------------------
echo "============================================================"
echo "REFLEXION"
echo "============================================================"
# Por que Linux no implementa directamente FCFS, SJF o RR?
#
# Linux es un sistema operativo de proposito general que debe
# manejar multiples procesos interactivos, tareas en segundo plano
# y sistemas multiusuario.
#
# Algoritmos como FCFS, SJF y RR son utiles para fines academicos,
# pero no escalan bien ni ofrecen la flexibilidad necesaria.
#
# El CFS busca repartir el CPU de forma "justa" entre procesos,
# utilizando conceptos como tiempo virtual, evitando la inanicion
# y ofreciendo mejor rendimiento en sistemas reales.
#
# En lugar de priorizar orden de llegada o rafagas cortas,
# Linux prioriza equidad y responsividad.
echo "Reflexion incluida en los comentarios del script."
echo "============================================================"

ESOCHOSFWARE