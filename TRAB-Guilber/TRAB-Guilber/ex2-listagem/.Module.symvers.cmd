cmd_/home/guilber/Documentos/TRAB-Guilber/ex2-listagem/Module.symvers := sed 's/\.ko$$/\.o/' /home/guilber/Documentos/TRAB-Guilber/ex2-listagem/modules.order | scripts/mod/modpost -m -a  -o /home/guilber/Documentos/TRAB-Guilber/ex2-listagem/Module.symvers -e -i Module.symvers   -T -