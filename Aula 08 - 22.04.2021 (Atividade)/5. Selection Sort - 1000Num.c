#include <stdio.h>
#include <time.h>
#define GREEN "\x1B[32m"
#define WHITE "\033[0m"

int sorteio[1000] = {893, 193, 968, 470, 171, 962, 600, 603, 791, 151, 700, 575, 494, 262, 75, 86, 106, 143, 870, 327, 469, 386, 26, 180, 215, 577, 500, 476, 482, 796, 816, 727, 340, 135, 196, 862, 449, 795, 465, 591, 297, 164, 166, 790, 778, 240, 875, 235, 734, 97, 561, 555, 586, 48, 515, 524, 348, 733, 691, 74, 72, 826, 269, 934, 626, 415, 750, 216, 711, 265, 381, 852, 42, 972, 276, 58, 823, 189, 612, 656, 126, 345, 703, 640, 282, 578, 14, 413, 446, 34, 371, 71, 448, 472, 286, 511, 736, 19, 362, 130, 990, 88, 757, 47, 945, 658, 355, 324, 62, 988, 901, 401, 2, 521, 439, 966, 199, 161, 36, 646, 632, 674, 508, 719, 692, 848, 33, 309, 957, 80, 923, 89, 191, 323, 866, 737, 783, 767, 137, 784, 639, 302, 222, 605, 992, 850, 365, 17, 357, 83, 708, 226, 283, 741, 887, 172, 809, 491, 351, 407, 217, 902, 335, 390, 973, 44, 897, 929, 895, 630, 921, 744, 346, 289, 453, 780, 997, 30, 916, 652, 724, 495, 223, 427, 660, 981, 643, 977, 844, 949, 92, 230, 73, 502, 418, 787, 198, 786, 817, 611, 732, 615, 837, 808, 461, 412, 234, 120, 392, 876, 32, 204, 333, 460, 504, 678, 552, 976, 394, 24, 943, 558, 553, 739, 519, 927, 979, 338, 681, 450, 82, 908, 481, 463, 157, 967, 195, 60, 51, 815, 637, 417, 781, 158, 723, 715, 627, 910, 356, 146, 155, 526, 188, 926, 959, 447, 758, 304, 813, 228, 872, 278, 907, 914, 52, 687, 925, 409, 628, 388, 358, 983, 885, 546, 489, 360, 676, 285, 123, 43, 686, 317, 498, 259, 138, 721, 888, 420, 802, 314, 726, 384, 174, 11, 462, 532, 698, 429, 185, 57, 861, 342, 882, 919, 366, 768, 624, 488, 961, 467, 664, 518, 207, 915, 880, 20, 798, 576, 717, 227, 761, 773, 621, 466, 955, 201, 229, 320, 996, 295, 145, 836, 457, 173, 592, 434, 109, 828, 341, 79, 28, 1000, 669, 954, 468, 625, 178, 464, 322, 651, 428, 131, 952, 722, 513, 182, 377, 522, 740, 170, 520, 373, 688, 122, 507, 747, 144, 970, 947, 924, 395, 668, 661, 389, 951, 128, 619, 512, 298, 139, 22, 939, 497, 978, 618, 484, 716, 806, 45, 777, 528, 991, 275, 712, 212, 101, 835, 580, 877, 296, 478, 251, 326, 563, 398, 46, 203, 95, 980, 974, 12, 31, 248, 743, 485, 585, 319, 774, 667, 3, 771, 496, 253, 918, 18, 316, 830, 995, 663, 249, 849, 631, 168, 853, 293, 479, 601, 367, 899, 539, 6, 537, 541, 187, 531, 59, 571, 911, 111, 243, 597, 804, 569, 689, 336, 579, 987, 102, 303, 770, 647, 225, 557, 194, 370, 352, 274, 623, 311, 13, 890, 999, 800, 948, 764, 884, 886, 530, 793, 55, 514, 588, 200, 865, 148, 490, 860, 684, 433, 696, 851, 272, 606, 818, 242, 564, 847, 1, 361, 589, 707, 67, 486, 329, 113, 149, 989, 402, 775, 572, 525, 16, 440, 825, 792, 380, 594, 922, 133, 679, 337, 90, 879, 318, 110, 788, 841, 416, 994, 64, 598, 140, 752, 610, 206, 695, 8, 666, 21, 864, 789, 477, 332, 903, 501, 96, 499, 177, 644, 445, 54, 252, 383, 273, 636, 247, 61, 889, 650, 53, 78, 487, 121, 814, 859, 267, 224, 831, 958, 455, 867, 869, 706, 107, 871, 250, 119, 245, 881, 554, 344, 662, 693, 608, 559, 665, 117, 759, 772, 480, 301, 208, 141, 900, 100, 810, 474, 763, 648, 116, 749, 91, 27, 548, 858, 543, 325, 510, 279, 581, 944, 634, 769, 49, 509, 256, 260, 930, 359, 99, 308, 291, 953, 905, 231, 375, 821, 76, 932, 928, 271, 354, 673, 257, 549, 81, 197, 165, 797, 63, 23, 339, 573, 98, 404, 998, 629, 353, 473, 150, 374, 506, 819, 975, 544, 527, 940, 411, 937, 372, 709, 960, 616, 368, 432, 391, 232, 437, 108, 160, 183, 762, 832, 751, 103, 405, 517, 350, 39, 112, 801, 237, 582, 104, 892, 281, 728, 755, 69, 387, 682, 364, 142, 152, 184, 699, 9, 264, 214, 595, 493, 85, 382, 550, 159, 857, 210, 909, 807, 935, 635, 855, 456, 441, 77, 454, 863, 25, 620, 321, 349, 969, 776, 268, 66, 805, 246, 685, 263, 868, 642, 735, 35, 369, 29, 65, 421, 655, 697, 87, 176, 290, 672, 68, 584, 746, 799, 993, 659, 913, 310, 942, 653, 829, 839, 820, 894, 745, 622, 270, 587, 933, 209, 147, 218, 277, 562, 442, 192, 483, 891, 403, 590, 10, 343, 451, 566, 986, 971, 824, 443, 406, 878, 931, 680, 965, 238, 127, 657, 94, 414, 397, 505, 7, 614, 963, 299, 56, 730, 545, 756, 596, 738, 452, 181, 956, 471, 638, 645, 904, 785, 599, 202, 300, 330, 938, 950, 551, 430, 827, 213, 40, 186, 153, 536, 328, 766, 941, 671, 704, 492, 239, 677, 294, 873, 607, 221, 523, 37, 713, 649, 547, 633, 731, 984, 883, 436, 305, 292, 714, 241, 408, 313, 568, 4, 163, 458, 70, 156, 306, 854, 125, 41, 5, 424, 906, 399, 964, 347, 765, 167, 760, 475, 754, 705, 675, 811, 534, 363, 396, 602, 444, 255, 690, 288, 641, 220, 219, 129, 753, 936, 236, 378, 280, 542, 710, 822, 459, 567, 438, 609, 50, 574, 529, 560, 233, 538, 533, 874, 211, 812, 516, 748, 794, 718, 593, 701, 307, 725, 694, 565, 425, 169, 134, 38, 896, 287, 115, 136, 258, 393, 670, 845, 205, 782, 84, 570, 803, 946, 419, 154, 124, 856, 315, 284, 261, 742, 720, 435, 503, 334, 312, 917, 779, 105, 729, 118, 266, 898, 379, 331, 179, 426, 423, 93, 376, 254, 613, 833, 654, 431, 422, 190, 617, 410, 556, 842, 834, 843, 15, 162, 982, 175, 535, 385, 114, 846, 840, 912, 540, 400, 244, 132, 838, 985, 583, 683, 604, 702, 920};

//ANTES DA ORDENAÇÃO
void exibir(int V[], int n){
    int i;
    for(i=0; i<1000; i++){
      printf("%.2d ", V[i]);
    }
    printf("\n");
}

//TROCAS E COMPARAÇÕES
void sortear(int V[], int n){
    int i, j, aux, min, trocas=0, compara=0;

    for(i=0; i<n-1; i++){
        min = i; 

        for(j=i+1; j<n; j++){
          
            //PARA CRESCENTE: <
            //PARA DECRESCENTE: >
            if(V[j] < V[min]){
              min = j;
            }
          compara++;
        }

        if(V[i] != V[min]){
            aux = V[i];
            V[i] = V[min];
            V[min] = aux;
            trocas++;
        }
    }

    printf("%s", GREEN);
    printf("\nTotal de Trocas: ");
    printf("%.2d \n", trocas);

    printf("Total de Comparações: ");
    printf("%.2d \n", compara);
    printf("%s", WHITE);
}

//METODO MAIN
int main(void) {
  
    int i;

    printf("\nAntes da Ordenação: \n");
    for(i=0; i<1000; i++){
        printf("%d ", sorteio[i]);
    }

    clock_t begin=clock(); //INICIO
    printf("\n\nExibir as trocas da ordenação:");
    sortear(sorteio, 1000);
    clock_t end=clock(); //FINAL

    printf("\nDepois da Ordenação: \n");
    for(i=0; i<1000; i++){
        printf("%.2d ", sorteio[i]);
    }

    //TEMPO DE EXECUÇÃO
    printf("\n\n");
    printf("%s", GREEN);
    printf("Tempo: %lf Segundos",(double)(end-begin) / CLOCKS_PER_SEC);
    printf("%s", WHITE);

    return 0;
}
