int convert(char* s) {
    switch(s[1]) {
        case '-': return 581; // W-SU
        case 'C': return 565; // UCT
        case 'R': return 559; // PRC
        case 'T': return 580; // UTC
        case 'c': return 486; // Iceland
        case 'g': return 379; // Egypt
        case 'w': return 502; // Kwajalein
        case 'B': switch(s[2]) {
            case '\0': return 477; // GB
            case '-': return 478; // GB-Eire
            default: return -1;
        }
        case 'E': switch(s[0]) {
            case 'C': return 373; // CET
            case 'E': return 378; // EET
            case 'M': return 504; // MET
            case 'W': return 582; // WET
            default: return -1;
        }
        case 'M': switch(s[3]) {
            case '\0': return 479; // GMT
            case '+': return 480; // GMT+0
            case '-': return 481; // GMT-0
            case '0': return 482; // GMT0
            default: return -1;
        }
        case 'O': switch(s[2]) {
            case 'C': return 561; // ROC
            case 'K': return 562; // ROK
            default: return -1;
        }
        case 'S': switch(s[3]) {
            case '5': return 382; // EST5EDT
            case '6': return 376; // CST6CDT
            case '7': return 509; // MST7MDT
            case '8': return 560; // PST8PDT
            case 'C': return 570; // US/Central
            case 'H': return 573; // US/Hawaii
            case 'I': return 574; // US/Indiana-Starke
            case 'S': return 579; // US/Samoa
            case '\0': switch(s[0]) {
                case 'E': return 381; // EST
                case 'H': return 485; // HST
                case 'M': return 508; // MST
                default: return -1;
            }
            case 'A': switch(s[5]) {
                case 'a': return 567; // US/Alaska
                case 'e': return 568; // US/Aleutian
                case 'i': return 569; // US/Arizona
                default: return -1;
            }
            case 'E': switch(s[7]) {
                case '-': return 571; // US/East-Indiana
                case 'e': return 572; // US/Eastern
                default: return -1;
            }
            case 'M': switch(s[4]) {
                case 'i': return 575; // US/Michigan
                case 'o': return 576; // US/Mountain
                default: return -1;
            }
            case 'P': switch(s[10]) {
                case '\0': return 577; // US/Pacific
                case '-': return 578; // US/Pacific-New
                default: return -1;
            }
            default: return -1;
        }
        case 'Z': switch(s[2]) {
            case '\0': return 511; // NZ
            case '-': return 512; // NZ-CHAT
            default: return -1;
        }
        case 'a': switch(s[2]) {
            case 'm': return 500; // Jamaica
            case 'p': return 501; // Japan
            case 'v': return 510; // Navajo
            case 'c': switch(s[11]) {
                case '\0': return 555; // Pacific/Yap
                case 'b': return 525; // Pacific/Gambier
                case 'c': return 542; // Pacific/Pitcairn
                case 'd': return 526; // Pacific/Guadalcanal
                case 'f': return 538; // Pacific/Norfolk
                case 'j': return 532; // Pacific/Kwajalein
                case 'l': return 554; // Pacific/Wallis
                case 'p': return 547; // Pacific/Saipan
                case 'q': return 534; // Pacific/Marquesas
                case 'w': return 535; // Pacific/Midway
                case 'a': switch(s[12]) {
                    case '\0': return 513; // Pacific/Apia
                    case 'f': return 523; // Pacific/Funafuti
                    case 'o': return 521; // Pacific/Fakaofo
                    case 'u': return 541; // Pacific/Palau
                    case 'w': return 550; // Pacific/Tarawa
                    case 'p': switch(s[8]) {
                        case 'G': return 524; // Pacific/Galapagos
                        case 'P': return 544; // Pacific/Ponape
                        default: return -1;
                    }
                    default: return -1;
                }
                case 'e': switch(s[8]) {
                    case 'E': return 520; // Pacific/Enderbury
                    case 'N': return 537; // Pacific/Niue
                    case 'W': return 553; // Pacific/Wake
                    default: return -1;
                }
                case 'g': switch(s[8]) {
                    case 'B': return 515; // Pacific/Bougainville
                    case 'T': return 551; // Pacific/Tongatapu
                    default: return -1;
                }
                case 'i': switch(s[8]) {
                    case 'F': return 522; // Pacific/Fiji
                    case 'K': return 530; // Pacific/Kiritimati
                    case 'T': return 549; // Pacific/Tahiti
                    default: return -1;
                }
                case 'k': switch(s[8]) {
                    case 'A': return 514; // Pacific/Auckland
                    case 'T': return 552; // Pacific/Truk
                    default: return -1;
                }
                case 'm': switch(s[8]) {
                    case 'G': return 527; // Pacific/Guam
                    case 'N': return 539; // Pacific/Noumea
                    default: return -1;
                }
                case 'n': switch(s[8]) {
                    case 'J': return 529; // Pacific/Johnston
                    case 'P': return 543; // Pacific/Pohnpei
                    default: return -1;
                }
                case 'o': switch(s[8]) {
                    case 'H': return 528; // Pacific/Honolulu
                    case 'P': return 540; // Pacific/Pago_Pago
                    case 'R': return 546; // Pacific/Rarotonga
                    case 'S': return 548; // Pacific/Samoa
                    default: return -1;
                }
                case 'r': switch(s[8]) {
                    case 'K': return 531; // Pacific/Kosrae
                    case 'N': return 536; // Pacific/Nauru
                    default: return -1;
                }
                case 't': switch(s[9]) {
                    case 'a': return 518; // Pacific/Easter
                    case 'f': return 519; // Pacific/Efate
                    case 'h': return 516; // Pacific/Chatham
                    case 'o': return 545; // Pacific/Port_Moresby
                    default: return -1;
                }
                case 'u': switch(s[8]) {
                    case 'C': return 517; // Pacific/Chuuk
                    case 'M': return 533; // Pacific/Majuro
                    default: return -1;
                }
                default: return -1;
            }
            case 'n': switch(s[7]) {
                case 'A': return 364; // Canada/Atlantic
                case 'C': return 365; // Canada/Central
                case 'M': return 368; // Canada/Mountain
                case 'N': return 369; // Canada/Newfoundland
                case 'P': return 370; // Canada/Pacific
                case 'S': return 371; // Canada/Saskatchewan
                case 'Y': return 372; // Canada/Yukon
                case 'E': switch(s[11]) {
                    case '-': return 366; // Canada/East-Saskatchewan
                    case 'e': return 367; // Canada/Eastern
                    default: return -1;
                }
                default: return -1;
            }
            default: return -1;
        }
        case 'e': switch(s[11]) {
            case 'N': return 505; // Mexico/BajaNorte
            case 'S': return 506; // Mexico/BajaSur
            case 'r': return 507; // Mexico/General
            default: return -1;
        }
        case 'f': switch(s[7]) {
            case 'E': return 21; // Africa/El_Aaiun
            case 'F': return 22; // Africa/Freetown
            case 'G': return 23; // Africa/Gaborone
            case 'H': return 24; // Africa/Harare
            case 'O': return 47; // Africa/Ouagadougou
            case 'P': return 48; // Africa/Porto-Novo
            case 'S': return 49; // Africa/Sao_Tome
            case 'W': return 53; // Africa/Windhoek
            case 'A': switch(s[8]) {
                case 'b': return 0; // Africa/Abidjan
                case 'c': return 1; // Africa/Accra
                case 'd': return 2; // Africa/Addis_Ababa
                case 'l': return 3; // Africa/Algiers
                case 's': switch(s[10]) {
                    case 'a': return 4; // Africa/Asmara
                    case 'e': return 5; // Africa/Asmera
                    default: return -1;
                }
                default: return -1;
            }
            case 'B': switch(s[10]) {
                case 'a': return 6; // Africa/Bamako
                case 'g': return 7; // Africa/Bangui
                case 'j': return 8; // Africa/Banjul
                case 'n': return 10; // Africa/Blantyre
                case 's': return 9; // Africa/Bissau
                case 'u': return 12; // Africa/Bujumbura
                case 'z': return 11; // Africa/Brazzaville
                default: return -1;
            }
            case 'C': switch(s[9]) {
                case 'i': return 13; // Africa/Cairo
                case 'n': return 16; // Africa/Conakry
                case 's': return 14; // Africa/Casablanca
                case 'u': return 15; // Africa/Ceuta
                default: return -1;
            }
            case 'D': switch(s[9]) {
                case 'i': return 19; // Africa/Djibouti
                case 'k': return 17; // Africa/Dakar
                case 'r': return 18; // Africa/Dar_es_Salaam
                case 'u': return 20; // Africa/Douala
                default: return -1;
            }
            case 'J': switch(s[8]) {
                case 'o': return 25; // Africa/Johannesburg
                case 'u': return 26; // Africa/Juba
                default: return -1;
            }
            case 'K': switch(s[9]) {
                case 'a': return 28; // Africa/Khartoum
                case 'g': return 29; // Africa/Kigali
                case 'm': return 27; // Africa/Kampala
                case 'n': return 30; // Africa/Kinshasa
                default: return -1;
            }
            case 'L': switch(s[10]) {
                case 'a': return 36; // Africa/Lusaka
                case 'e': return 33; // Africa/Lome
                case 'n': return 34; // Africa/Luanda
                case 'o': return 31; // Africa/Lagos
                case 'r': return 32; // Africa/Libreville
                case 'u': return 35; // Africa/Lubumbashi
                default: return -1;
            }
            case 'M': switch(s[9]) {
                case 'a': return 40; // Africa/Mbabane
                case 'g': return 41; // Africa/Mogadishu
                case 'l': return 37; // Africa/Malabo
                case 'n': return 42; // Africa/Monrovia
                case 'p': return 38; // Africa/Maputo
                case 's': return 39; // Africa/Maseru
                default: return -1;
            }
            case 'N': switch(s[8]) {
                case 'a': return 43; // Africa/Nairobi
                case 'd': return 44; // Africa/Ndjamena
                case 'i': return 45; // Africa/Niamey
                case 'o': return 46; // Africa/Nouakchott
                default: return -1;
            }
            case 'T': switch(s[8]) {
                case 'i': return 50; // Africa/Timbuktu
                case 'r': return 51; // Africa/Tripoli
                case 'u': return 52; // Africa/Tunis
                default: return -1;
            }
            default: return -1;
        }
        case 'h': switch(s[6]) {
            case 'C': return 374; // Chile/Continental
            case 'E': return 375; // Chile/EasterIsland
            default: return -1;
        }
        case 'i': switch(s[0]) {
            case 'E': return 380; // Eire
            case 'L': return 503; // Libya
            case 'S': return 563; // Singapore
            default: return -1;
        }
        case 'm': switch(s[11]) {
            case 'B': return 200; // America/St_Barthelemy
            case 'J': return 201; // America/St_Johns
            case 'K': return 202; // America/St_Kitts
            case 'L': return 203; // America/St_Lucia
            case 'P': return 144; // America/La_Paz
            case 'S': return 109; // America/El_Salvador
            case 'T': return 204; // America/St_Thomas
            case 'V': return 205; // America/St_Vincent
            case 'f': return 206; // America/Swift_Current
            case 'x': return 142; // America/Knox_IN
            case 'y': return 121; // America/Guayaquil
            case '_': switch(s[8]) {
                case 'B': return 82; // America/Boa_Vista
                case 'L': return 146; // America/Los_Angeles
                case 'N': return 168; // America/New_York
                case 'R': return 190; // America/Rio_Branco
                case 'S': return 196; // America/Sao_Paulo
                default: return -1;
            }
            case 'a': switch(s[8]) {
                case 'A': return 75; // America/Atka
                case 'G': return 122; // America/Guyana
                case 'H': return 124; // America/Havana
                case 'J': return 137; // America/Jamaica
                case 'L': return 145; // America/Lima
                case 'R': return 191; // America/Rosario
                case 'C': switch(s[14]) {
                    case '\0': return 99; // America/Cuiaba
                    case 'H': return 95; // America/Coral_Harbour
                    case 'o': return 100; // America/Curacao
                    case 'r': return 90; // America/Catamarca
                    case 's': return 89; // America/Caracas
                    default: return -1;
                }
                case 'M': switch(s[12]) {
                    case 'g': return 150; // America/Managua
                    case 'm': return 154; // America/Matamoros
                    case 't': return 155; // America/Mazatlan
                    case 'u': return 151; // America/Manaus
                    default: return -1;
                }
                case 'P': switch(s[10]) {
                    case 'n': return 176; // America/Panama
                    case 'r': return 178; // America/Paramaribo
                    default: return -1;
                }
                default: return -1;
            }
            case 'b': switch(s[8]) {
                case 'A': return 72; // America/Aruba
                case 'B': return 78; // America/Barbados
                case 'C': return 86; // America/Cambridge_Bay
                default: return -1;
            }
            case 'c': switch(s[12]) {
                case 'a': return 93; // America/Chicago
                case 'e': return 114; // America/Glace_Bay
                case 'o': return 213; // America/Vancouver
                case 't': return 162; // America/Moncton
                case 'u': return 88; // America/Cancun
                default: return -1;
            }
            case 'd': switch(s[8]) {
                case 'C': return 96; // America/Cordoba
                case 'G': return 119; // America/Guadeloupe
                case 'M': return 156; // America/Mendoza
                default: return -1;
            }
            case 'e': switch(s[8]) {
                case 'B': return 79; // America/Belem
                case 'C': return 91; // America/Cayenne
                case 'E': return 110; // America/Ensenada
                case 'J': return 139; // America/Juneau
                case 'L': return 148; // America/Lower_Princes
                case 'M': return 149; // America/Maceio
                case 'N': return 170; // America/Nome
                case 'P': return 179; // America/Phoenix
                case 'A': switch(s[20]) {
                    case '_': return 64; // America/Argentina/La_Rioja
                    case 'c': return 70; // America/Argentina/Tucuman
                    case 'e': return 59; // America/Argentina/Buenos_Aires
                    case 'h': return 71; // America/Argentina/Ushuaia
                    case 'j': return 63; // America/Argentina/Jujuy
                    case 'l': return 67; // America/Argentina/Salta
                    case 'm': return 61; // America/Argentina/ComodRivadavia
                    case 'o': return 66; // America/Argentina/Rio_Gallegos
                    case 'r': return 62; // America/Argentina/Cordoba
                    case 't': return 60; // America/Argentina/Catamarca
                    case 'n': switch(s[22]) {
                        case 'J': return 68; // America/Argentina/San_Juan
                        case 'L': return 69; // America/Argentina/San_Luis
                        case 'o': return 65; // America/Argentina/Mendoza
                        default: return -1;
                    }
                    default: return -1;
                }
                default: return -1;
            }
            case 'g': switch(s[8]) {
                case 'A': return 58; // America/Araguaina
                case 'P': return 177; // America/Pangnirtung
                case 'V': return 214; // America/Virgin
                default: return -1;
            }
            case 'h': switch(s[8]) {
                case 'A': return 55; // America/Anchorage
                case 'C': return 94; // America/Chihuahua
                default: return -1;
            }
            case 'i': switch(s[10]) {
                case 'c': return 187; // America/Recife
                case 'g': return 188; // America/Regina
                case 'm': return 106; // America/Dominica
                case 'p': return 169; // America/Nipigon
                case 't': return 57; // America/Antigua
                case 'u': return 147; // America/Louisville
                case 'x': return 160; // America/Mexico_City
                case 'd': switch(s[16]) {
                    case 'I': return 126; // America/Indiana/Indianapolis
                    case 'K': return 127; // America/Indiana/Knox
                    case 'M': return 128; // America/Indiana/Marengo
                    case 'P': return 129; // America/Indiana/Petersburg
                    case 'T': return 130; // America/Indiana/Tell_City
                    case 'W': return 133; // America/Indiana/Winamac
                    case 'o': return 134; // America/Indianapolis
                    case 'V': switch(s[17]) {
                        case 'e': return 131; // America/Indiana/Vevay
                        case 'i': return 132; // America/Indiana/Vincennes
                        default: return -1;
                    }
                    default: return -1;
                }
                case 'h': switch(s[13]) {
                    case '\0': return 76; // America/Bahia
                    case '_': return 77; // America/Bahia_Banderas
                    default: return -1;
                }
                case 'l': switch(s[8]) {
                    case 'B': return 80; // America/Belize
                    case 'H': return 123; // America/Halifax
                    default: return -1;
                }
                case 'r': switch(s[9]) {
                    case 'a': return 152; // America/Marigot
                    case 'e': return 158; // America/Merida
                    default: return -1;
                }
                default: return -1;
            }
            case 'k': switch(s[9]) {
                case 'a': return 186; // America/Rankin_Inlet
                case 'd': return 54; // America/Adak
                case 'i': return 199; // America/Sitka
                case 't': return 74; // America/Atikokan
                default: return -1;
            }
            case 'l': switch(s[8]) {
                case 'I': return 136; // America/Iqaluit
                case 'K': return 143; // America/Kralendijk
                case 'M': return 159; // America/Metlakatla
                case 'T': return 208; // America/Thule
                case 'Y': return 218; // America/Yellowknife
                default: return -1;
            }
            case 'm': switch(s[8]) {
                case 'C': return 92; // America/Cayman
                case 'D': return 101; // America/Danmarkshavn
                case 'H': return 125; // America/Hermosillo
                default: return -1;
            }
            case 'n': switch(s[9]) {
                case 'a': return 185; // America/Rainy_River
                case 'h': return 209; // America/Thunder_Bay
                case 'i': return 216; // America/Winnipeg
                case 'j': return 175; // America/Ojinaga
                case 'l': return 81; // America/Blanc-Sablon
                case 's': return 73; // America/Asuncion
                case 'u': return 85; // America/Buenos_Aires
                case 'r': switch(s[10]) {
                    case 'a': return 117; // America/Grand_Turk
                    case 'e': return 118; // America/Grenada
                    default: return -1;
                }
                default: return -1;
            }
            case 'o': switch(s[8]) {
                case 'B': return 83; // America/Bogota
                case 'E': return 107; // America/Edmonton
                case 'M': return 157; // America/Menominee
                case 'N': return 171; // America/Noronha
                case 'R': return 189; // America/Resolute
                case 'T': return 211; // America/Toronto
                default: return -1;
            }
            case 'p': switch(s[8]) {
                case 'C': return 87; // America/Campo_Grande
                case 'S': return 198; // America/Shiprock
                default: return -1;
            }
            case 'r': switch(s[8]) {
                case 'D': return 105; // America/Detroit
                case 'P': return 184; // America/Puerto_Rico
                case 'S': return 197; // America/Scoresbysund
                default: return -1;
            }
            case 's': switch(s[8]) {
                case 'B': return 84; // America/Boise
                case 'C': return 98; // America/Creston
                case 'G': return 116; // America/Goose_Bay
                case 'N': return 167; // America/Nassau
                case 'D': switch(s[14]) {
                    case '\0': return 102; // America/Dawson
                    case '_': return 103; // America/Dawson_Creek
                    default: return -1;
                }
                default: return -1;
            }
            case 't': switch(s[14]) {
                case 'A': return 182; // America/Porto_Acre
                case 'I': return 192; // America/Santa_Isabel
                case 'R': return 97; // America/Costa_Rica
                case 'V': return 183; // America/Porto_Velho
                case 'b': return 115; // America/Godthab
                case 'f': return 181; // America/Port_of_Spain
                case 'g': return 194; // America/Santiago
                case 'o': return 215; // America/Whitehorse
                case 'u': return 180; // America/Port-au-Prince
                case 'D': switch(s[21]) {
                    case '\0': return 195; // America/Santo_Domingo
                    case 'B': return 172; // America/North_Dakota/Beulah
                    case 'C': return 173; // America/North_Dakota/Center
                    case 'N': return 174; // America/North_Dakota/New_Salem
                    default: return -1;
                }
                case 'a': switch(s[8]) {
                    case 'F': return 112; // America/Fort_Wayne
                    case 'G': return 120; // America/Guatemala
                    case 'M': return 165; // America/Montreal
                    case 'T': return 212; // America/Tortola
                    default: return -1;
                }
                case 'e': switch(s[13]) {
                    case 'N': return 111; // America/Fort_Nelson
                    case 'l': return 113; // America/Fortaleza
                    case 'r': return 193; // America/Santarem
                    default: return -1;
                }
                case 'i': switch(s[9]) {
                    case 'a': return 153; // America/Martinique
                    case 'o': return 164; // America/Montevideo
                    default: return -1;
                }
                case 'k': switch(s[17]) {
                    case 'L': return 140; // America/Kentucky/Louisville
                    case 'M': return 141; // America/Kentucky/Monticello
                    default: return -1;
                }
                case 'r': switch(s[12]) {
                    case 'e': return 163; // America/Monterrey
                    case 's': return 166; // America/Montserrat
                    default: return -1;
                }
                default: return -1;
            }
            case 'u': switch(s[12]) {
                case 'a': return 210; // America/Tijuana
                case 'c': return 207; // America/Tegucigalpa
                case 'e': return 161; // America/Miquelon
                case 'i': return 56; // America/Anguilla
                case 'n': return 108; // America/Eirunepe
                case 't': return 217; // America/Yakutat
                case 'y': return 138; // America/Jujuy
                default: return -1;
            }
            case 'v': switch(s[8]) {
                case 'D': return 104; // America/Denver
                case 'I': return 135; // America/Inuvik
                default: return -1;
            }
            default: return -1;
        }
        case 'n': switch(s[9]) {
            case '\0': return 566; // Universal
            case 'c': return 490; // Indian/Cocos
            case 'h': return 493; // Indian/Mahe
            case 'l': return 494; // Indian/Maldives
            case 'm': return 491; // Indian/Comoro
            case 't': return 487; // Indian/Antananarivo
            case 'y': return 496; // Indian/Mayotte
            case 'a': switch(s[13]) {
                case '\0': return 488; // Indian/Chagos
                case 'M': return 224; // Antarctica/McMurdo
                case 'c': return 222; // Antarctica/Macquarie
                case 'l': return 225; // Antarctica/Palmer
                case 'm': return 221; // Antarctica/DumontDUrville
                case 't': return 226; // Antarctica/Rothera
                case 'u': return 227; // Antarctica/South_Pole
                case 'v': return 220; // Antarctica/Davis
                case 'w': return 223; // Antarctica/Mawson
                case 'o': switch(s[11]) {
                    case 'S': return 228; // Antarctica/Syowa
                    case 'T': return 229; // Antarctica/Troll
                    default: return -1;
                }
                case 's': switch(s[11]) {
                    case 'C': return 219; // Antarctica/Casey
                    case 'V': return 230; // Antarctica/Vostok
                    default: return -1;
                }
                default: return -1;
            }
            case 'r': switch(s[7]) {
                case 'C': return 489; // Indian/Christmas
                case 'K': return 492; // Indian/Kerguelen
                default: return -1;
            }
            case 'u': switch(s[7]) {
                case 'M': return 495; // Indian/Mauritius
                case 'R': return 497; // Indian/Reunion
                default: return -1;
            }
            default: return -1;
        }
        case 'o': switch(s[2]) {
            case 'l': return 556; // Poland
            case 'n': return 484; // Hongkong
            case 'r': return 557; // Portugal
            case 's': return 558; // posixrules
            default: return -1;
        }
        case 'r': switch(s[0]) {
            case 'A': return 231; // Arctic/Longyearbyen
            case 'G': return 483; // Greenwich
            case 'I': return 498; // Iran
            case 'B': switch(s[7]) {
                case 'A': return 360; // Brazil/Acre
                case 'D': return 361; // Brazil/DeNoronha
                case 'E': return 362; // Brazil/East
                case 'W': return 363; // Brazil/West
                default: return -1;
            }
            default: return -1;
        }
        case 's': switch(s[5]) {
            case 'G': return 259; // Asia/Gaza
            case 'l': return 499; // Israel
            case 'A': switch(s[9]) {
                case '\0': return 232; // Asia/Aden
                case 'a': return 238; // Asia/Ashgabat
                case 'b': return 237; // Asia/Aqtobe
                case 'h': return 239; // Asia/Ashkhabad
                case 'n': return 234; // Asia/Amman
                case 't': return 233; // Asia/Almaty
                case 'u': return 236; // Asia/Aqtau
                case 'y': return 235; // Asia/Anadyr
                default: return -1;
            }
            case 'B': switch(s[7]) {
                case 'g': return 240; // Asia/Baghdad
                case 'h': return 241; // Asia/Bahrain
                case 'i': return 244; // Asia/Beirut
                case 'k': return 242; // Asia/Baku
                case 'n': return 243; // Asia/Bangkok
                case 's': return 245; // Asia/Bishkek
                case 'u': return 246; // Asia/Brunei
                default: return -1;
            }
            case 'C': switch(s[10]) {
                case '\0': return 248; // Asia/Chita
                case 'a': return 249; // Asia/Choibalsan
                case 'b': return 252; // Asia/Colombo
                case 'k': return 251; // Asia/Chungking
                case 'q': return 250; // Asia/Chongqing
                case 't': return 247; // Asia/Calcutta
                default: return -1;
            }
            case 'D': switch(s[7]) {
                case 'a': return 255; // Asia/Dhaka
                case 'b': return 257; // Asia/Dubai
                case 'c': return 253; // Asia/Dacca
                case 'l': return 256; // Asia/Dili
                case 'm': return 254; // Asia/Damascus
                case 's': return 258; // Asia/Dushanbe
                default: return -1;
            }
            case 'H': switch(s[7]) {
                case '_': return 262; // Asia/Ho_Chi_Minh
                case 'b': return 261; // Asia/Hebron
                case 'n': return 263; // Asia/Hong_Kong
                case 'r': return 260; // Asia/Harbin
                case 'v': return 264; // Asia/Hovd
                default: return -1;
            }
            case 'I': switch(s[6]) {
                case 'r': return 265; // Asia/Irkutsk
                case 's': return 266; // Asia/Istanbul
                default: return -1;
            }
            case 'J': switch(s[7]) {
                case 'k': return 267; // Asia/Jakarta
                case 'r': return 269; // Asia/Jerusalem
                case 'y': return 268; // Asia/Jayapura
                default: return -1;
            }
            case 'K': switch(s[7]) {
                case 'b': return 270; // Asia/Kabul
                case 'c': return 280; // Asia/Kuching
                case 'l': return 277; // Asia/Kolkata
                case 'm': return 271; // Asia/Kamchatka
                case 'r': return 272; // Asia/Karachi
                case 's': return 273; // Asia/Kashgar
                case 'w': return 281; // Asia/Kuwait
                case 'a': switch(s[6]) {
                    case 'h': return 276; // Asia/Khandyga
                    case 'r': return 278; // Asia/Krasnoyarsk
                    case 'u': return 279; // Asia/Kuala_Lumpur
                    default: return -1;
                }
                case 't': switch(s[8]) {
                    case 'h': return 274; // Asia/Kathmandu
                    case 'm': return 275; // Asia/Katmandu
                    default: return -1;
                }
                default: return -1;
            }
            case 'M': switch(s[9]) {
                case 'a': return 287; // Asia/Muscat
                case 'd': return 284; // Asia/Magadan
                case 'l': return 286; // Asia/Manila
                case 'o': return 282; // Asia/Macao
                case 's': return 285; // Asia/Makassar
                case 'u': return 283; // Asia/Macau
                default: return -1;
            }
            case 'N': switch(s[11]) {
                case 'a': return 288; // Asia/Nicosia
                case 'b': return 290; // Asia/Novosibirsk
                case 'z': return 289; // Asia/Novokuznetsk
                default: return -1;
            }
            case 'O': switch(s[6]) {
                case 'm': return 291; // Asia/Omsk
                case 'r': return 292; // Asia/Oral
                default: return -1;
            }
            case 'P': switch(s[6]) {
                case 'h': return 293; // Asia/Phnom_Penh
                case 'o': return 294; // Asia/Pontianak
                case 'y': return 295; // Asia/Pyongyang
                default: return -1;
            }
            case 'Q': switch(s[6]) {
                case 'a': return 296; // Asia/Qatar
                case 'y': return 297; // Asia/Qyzylorda
                default: return -1;
            }
            case 'R': switch(s[6]) {
                case 'a': return 298; // Asia/Rangoon
                case 'i': return 299; // Asia/Riyadh
                default: return -1;
            }
            case 'S': switch(s[7]) {
                case 'a': return 304; // Asia/Shanghai
                case 'e': return 306; // Asia/Srednekolymsk
                case 'i': return 300; // Asia/Saigon
                case 'k': return 301; // Asia/Sakhalin
                case 'm': return 302; // Asia/Samarkand
                case 'n': return 305; // Asia/Singapore
                case 'o': return 303; // Asia/Seoul
                default: return -1;
            }
            case 'T': switch(s[9]) {
                case 'A': return 311; // Asia/Tel_Aviv
                case 'a': return 310; // Asia/Tehran
                case 'b': return 312; // Asia/Thimbu
                case 'e': return 307; // Asia/Taipei
                case 'i': return 309; // Asia/Tbilisi
                case 'k': return 308; // Asia/Tashkent
                case 'o': return 314; // Asia/Tokyo
                case 'p': return 313; // Asia/Thimphu
                default: return -1;
            }
            case 'U': switch(s[9]) {
                case 'N': return 319; // Asia/Ust-Nera
                case '_': return 317; // Asia/Ulan_Bator
                case 'g': return 315; // Asia/Ujung_Pandang
                case 'n': return 316; // Asia/Ulaanbaatar
                case 'q': return 318; // Asia/Urumqi
                default: return -1;
            }
            case 'V': switch(s[6]) {
                case 'i': return 320; // Asia/Vientiane
                case 'l': return 321; // Asia/Vladivostok
                default: return -1;
            }
            case 'Y': switch(s[8]) {
                case 'a': return 323; // Asia/Yekaterinburg
                case 'e': return 324; // Asia/Yerevan
                case 'u': return 322; // Asia/Yakutsk
                default: return -1;
            }
            default: return -1;
        }
        case 't': switch(s[7]) {
            case '0': return 412; // Etc/GMT0
            case 'e': return 413; // Etc/Greenwich
            case 'u': return 417; // Etc/Zulu
            case 'v': return 415; // Etc/Universal
            case '\0': switch(s[5]) {
                case 'C': return 414; // Etc/UCT
                case 'M': return 383; // Etc/GMT
                case 'T': return 416; // Etc/UTC
                default: return -1;
            }
            case '+': switch(s[8]) {
                case '0': return 384; // Etc/GMT+0
                case '2': return 389; // Etc/GMT+2
                case '3': return 390; // Etc/GMT+3
                case '4': return 391; // Etc/GMT+4
                case '5': return 392; // Etc/GMT+5
                case '6': return 393; // Etc/GMT+6
                case '7': return 394; // Etc/GMT+7
                case '8': return 395; // Etc/GMT+8
                case '9': return 396; // Etc/GMT+9
                case '1': switch(s[9]) {
                    case '\0': return 385; // Etc/GMT+1
                    case '0': return 386; // Etc/GMT+10
                    case '1': return 387; // Etc/GMT+11
                    case '2': return 388; // Etc/GMT+12
                    default: return -1;
                }
                default: return -1;
            }
            case '-': switch(s[8]) {
                case '0': return 397; // Etc/GMT-0
                case '2': return 404; // Etc/GMT-2
                case '3': return 405; // Etc/GMT-3
                case '4': return 406; // Etc/GMT-4
                case '5': return 407; // Etc/GMT-5
                case '6': return 408; // Etc/GMT-6
                case '7': return 409; // Etc/GMT-7
                case '8': return 410; // Etc/GMT-8
                case '9': return 411; // Etc/GMT-9
                case '1': switch(s[9]) {
                    case '\0': return 398; // Etc/GMT-1
                    case '0': return 399; // Etc/GMT-10
                    case '1': return 400; // Etc/GMT-11
                    case '2': return 401; // Etc/GMT-12
                    case '3': return 402; // Etc/GMT-13
                    case '4': return 403; // Etc/GMT-14
                    default: return -1;
                }
                default: return -1;
            }
            case 'c': switch(s[13]) {
                case 'M': return 331; // Atlantic/Jan_Mayen
                case '_': return 328; // Atlantic/Cape_Verde
                case 'h': return 334; // Atlantic/South_Georgia
                case 'i': return 332; // Atlantic/Madeira
                case 'j': return 333; // Atlantic/Reykjavik
                case 'l': return 336; // Atlantic/Stanley
                case 'o': return 329; // Atlantic/Faeroe
                case 'r': return 327; // Atlantic/Canary
                case 'u': return 326; // Atlantic/Bermuda
                case 'e': switch(s[9]) {
                    case 'A': return 325; // Atlantic/Azores
                    case 'F': return 330; // Atlantic/Faroe
                    case 'S': return 335; // Atlantic/St_Helena
                    default: return -1;
                }
                default: return -1;
            }
            default: return -1;
        }
        case 'u': switch(s[0]) {
            case 'C': return 377; // Cuba
            case 'T': return 564; // Turkey
            case 'Z': return 583; // Zulu
            case 'A': switch(s[10]) {
                case 'D': return 343; // Australia/Darwin
                case 'E': return 344; // Australia/Eucla
                case 'H': return 345; // Australia/Hobart
                case 'M': return 349; // Australia/Melbourne
                case 'P': return 352; // Australia/Perth
                case 'Q': return 353; // Australia/Queensland
                case 'T': return 356; // Australia/Tasmania
                case 'V': return 357; // Australia/Victoria
                case 'W': return 358; // Australia/West
                case 'Y': return 359; // Australia/Yancowinna
                case 'A': switch(s[11]) {
                    case 'C': return 337; // Australia/ACT
                    case 'd': return 338; // Australia/Adelaide
                    default: return -1;
                }
                case 'B': switch(s[12]) {
                    case 'i': return 339; // Australia/Brisbane
                    case 'o': return 340; // Australia/Broken_Hill
                    default: return -1;
                }
                case 'C': switch(s[11]) {
                    case 'a': return 341; // Australia/Canberra
                    case 'u': return 342; // Australia/Currie
                    default: return -1;
                }
                case 'L': switch(s[11]) {
                    case 'H': return 346; // Australia/LHI
                    case 'i': return 347; // Australia/Lindeman
                    case 'o': return 348; // Australia/Lord_Howe
                    default: return -1;
                }
                case 'N': switch(s[11]) {
                    case 'S': return 351; // Australia/NSW
                    case 'o': return 350; // Australia/North
                    default: return -1;
                }
                case 'S': switch(s[11]) {
                    case 'o': return 354; // Australia/South
                    case 'y': return 355; // Australia/Sydney
                    default: return -1;
                }
                default: return -1;
            }
            case 'E': switch(s[7]) {
                case 'D': return 431; // Europe/Dublin
                case 'H': return 434; // Europe/Helsinki
                case 'J': return 437; // Europe/Jersey
                case 'N': return 450; // Europe/Nicosia
                case 'O': return 451; // Europe/Oslo
                case 'U': return 467; // Europe/Uzhgorod
                case 'W': return 473; // Europe/Warsaw
                case 'A': switch(s[8]) {
                    case 'm': return 418; // Europe/Amsterdam
                    case 'n': return 419; // Europe/Andorra
                    case 't': return 420; // Europe/Athens
                    default: return -1;
                }
                case 'B': switch(s[10]) {
                    case 'a': return 427; // Europe/Budapest
                    case 'f': return 421; // Europe/Belfast
                    case 'g': return 422; // Europe/Belgrade
                    case 'h': return 426; // Europe/Bucharest
                    case 'i': return 428; // Europe/Busingen
                    case 'l': return 423; // Europe/Berlin
                    case 's': return 425; // Europe/Brussels
                    case 't': return 424; // Europe/Bratislava
                    default: return -1;
                }
                case 'C': switch(s[8]) {
                    case 'h': return 429; // Europe/Chisinau
                    case 'o': return 430; // Europe/Copenhagen
                    default: return -1;
                }
                case 'G': switch(s[8]) {
                    case 'i': return 432; // Europe/Gibraltar
                    case 'u': return 433; // Europe/Guernsey
                    default: return -1;
                }
                case 'I': switch(s[9]) {
                    case 'l': return 435; // Europe/Isle_of_Man
                    case 't': return 436; // Europe/Istanbul
                    default: return -1;
                }
                case 'K': switch(s[8]) {
                    case 'a': return 438; // Europe/Kaliningrad
                    case 'i': return 439; // Europe/Kiev
                    default: return -1;
                }
                case 'L': switch(s[8]) {
                    case 'i': return 440; // Europe/Lisbon
                    case 'j': return 441; // Europe/Ljubljana
                    case 'o': return 442; // Europe/London
                    case 'u': return 443; // Europe/Luxembourg
                    default: return -1;
                }
                case 'M': switch(s[10]) {
                    case 'a': return 448; // Europe/Monaco
                    case 'c': return 449; // Europe/Moscow
                    case 'i': return 446; // Europe/Mariehamn
                    case 'r': return 444; // Europe/Madrid
                    case 's': return 447; // Europe/Minsk
                    case 't': return 445; // Europe/Malta
                    default: return -1;
                }
                case 'P': switch(s[8]) {
                    case 'a': return 452; // Europe/Paris
                    case 'o': return 453; // Europe/Podgorica
                    case 'r': return 454; // Europe/Prague
                    default: return -1;
                }
                case 'R': switch(s[8]) {
                    case 'i': return 455; // Europe/Riga
                    case 'o': return 456; // Europe/Rome
                    default: return -1;
                }
                case 'S': switch(s[10]) {
                    case '_': return 458; // Europe/San_Marino
                    case 'c': return 463; // Europe/Stockholm
                    case 'f': return 460; // Europe/Simferopol
                    case 'i': return 462; // Europe/Sofia
                    case 'p': return 461; // Europe/Skopje
                    case 'a': switch(s[9]) {
                        case 'm': return 457; // Europe/Samara
                        case 'r': return 459; // Europe/Sarajevo
                        default: return -1;
                    }
                    default: return -1;
                }
                case 'T': switch(s[11]) {
                    case 'i': return 464; // Europe/Tallinn
                    case 'n': return 465; // Europe/Tirane
                    case 's': return 466; // Europe/Tiraspol
                    default: return -1;
                }
                case 'V': switch(s[11]) {
                    case 'c': return 469; // Europe/Vatican
                    case 'i': return 471; // Europe/Vilnius
                    case 'n': return 470; // Europe/Vienna
                    case 'o': return 472; // Europe/Volgograd
                    case 'z': return 468; // Europe/Vaduz
                    default: return -1;
                }
                case 'Z': switch(s[9]) {
                    case 'g': return 474; // Europe/Zagreb
                    case 'p': return 475; // Europe/Zaporozhye
                    case 'r': return 476; // Europe/Zurich
                    default: return -1;
                }
                default: return -1;
            }
            default: return -1;
        }
        default: return -1;
    }
}
