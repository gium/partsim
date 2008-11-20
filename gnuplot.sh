#! /bin/sh

FICHIER=test
EXE=simulateur

rm -f "${FICHIER}"
./${EXE} > "${FICHIER}"

TMP=$(mktemp)			# Faire un fichier temporaire
cat > "${TMP}" <<EOF
splot "${FICHIER}" using 1:2:3 palette  with dots
EOF

gnuplot -persist "${TMP}"

rm -f "${TMP}"
