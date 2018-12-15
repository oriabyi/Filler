# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oriabyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 13:54:03 by oriabyi           #+#    #+#              #
#    Updated: 2018/11/26 14:14:09 by oriabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mre

FILLER_BOT := oriabyi.filler
VM := vm.filler

FILLER_PATH := filler/
VM_PATH := vm/

all:
	@ make -C $(FILLER_PATH)
	@ make -C $(VM_PATH)
	@ ln -fs $(FILLER_PATH)$(FILLER_BOT) $(FILLER_BOT)
	@ ln -fs $(VM_PATH)$(VM) $(VM)
	@ chmod 744 $(FILLER_BOT) $(VM)

mre:
	@ make mre -C $(FILLER_PATH)
	@ make mre -C $(VM_PATH)
	@ ln -fs $(FILLER_PATH)$(FILLER_BOT) $(FILLER_BOT)
	@ ln -fs $(VM_PATH)$(VM) $(VM)
	@ chmod 744 $(FILLER_BOT) $(VM)

clean:
	make clean -C $(FILLER_PATH)
	make clean -C $(VM_PATH)

fclean:
	make fclean -C $(FILLER_PATH)
	make fclean -C $(VM_PATH)
	rm -f $(FILLER_BOT) $(VM)

re: fclean all
