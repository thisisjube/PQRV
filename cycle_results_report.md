# Cycle Measurement Comparison (HEAD vs. working tree)

Old = committed results (`HEAD`, cb3ee30), New = current uncommitted results.

- **Δ cycles** = old − new (positive = fewer cycles = faster)
- **Rel. speedup** = (old − new) / old (positive = faster)
- Changes with |rel.| ≥ 1 % are **bold**; smaller changes are within typical measurement noise.
- Only non-result change in the diff: `TARGET_IP` in `Kyber/RV64/Makclausefile` and `ntt/Makefile` changed from `192.168.123.99` to `k230-0`. No source code changed.

## Summary: top-level operations

| Directory | Config | Scheme | Operation | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---|---|---|---:|---:|---:|---:|
| Dilithium/RV64 | results_rv64im | Dilithium2 | Keypair | 538,426 | 519,986 | +18,440 | +3.42 % |
| Dilithium/RV64 | results_rv64im | Dilithium2 | Sign with rand | 2,123,775 | 2,038,452 | +85,323 | +4.02 % |
| Dilithium/RV64 | results_rv64im | Dilithium2 | Verify | 588,395 | 571,807 | +16,588 | +2.82 % |
| Dilithium/RV64 | results_rv64im | Dilithium3 | Keypair | 919,823 | 894,817 | +25,006 | +2.72 % |
| Dilithium/RV64 | results_rv64im | Dilithium3 | Sign with rand | 3,332,922 | 3,238,436 | +94,486 | +2.83 % |
| Dilithium/RV64 | results_rv64im | Dilithium3 | Verify | 938,862 | 912,327 | +26,535 | +2.83 % |
| Dilithium/RV64 | results_rv64im | Dilithium5 | Keypair | 1,499,165 | 1,455,064 | +44,101 | +2.94 % |
| Dilithium/RV64 | results_rv64im | Dilithium5 | Sign with rand | 4,106,997 | 3,953,280 | +153,717 | +3.74 % |
| Dilithium/RV64 | results_rv64im | Dilithium5 | Verify | 1,553,779 | 1,504,774 | +49,005 | +3.15 % |
| Dilithium/RV64 | results_rv64imb | Dilithium2 | Keypair | 448,575 | 431,087 | +17,488 | +3.90 % |
| Dilithium/RV64 | results_rv64imb | Dilithium2 | Sign with rand | 1,939,463 | 1,888,715 | +50,748 | +2.62 % |
| Dilithium/RV64 | results_rv64imb | Dilithium2 | Verify | 503,871 | 486,812 | +17,059 | +3.39 % |
| Dilithium/RV64 | results_rv64imb | Dilithium3 | Keypair | 753,005 | 731,649 | +21,356 | +2.84 % |
| Dilithium/RV64 | results_rv64imb | Dilithium3 | Sign with rand | 3,085,235 | 2,985,823 | +99,412 | +3.22 % |
| Dilithium/RV64 | results_rv64imb | Dilithium3 | Verify | 790,796 | 763,777 | +27,019 | +3.42 % |
| Dilithium/RV64 | results_rv64imb | Dilithium5 | Keypair | 1,216,507 | 1,180,977 | +35,530 | +2.92 % |
| Dilithium/RV64 | results_rv64imb | Dilithium5 | Sign with rand | 3,700,091 | 3,578,512 | +121,579 | +3.29 % |
| Dilithium/RV64 | results_rv64imb | Dilithium5 | Verify | 1,283,450 | 1,243,679 | +39,771 | +3.10 % |
| Dilithium/RV64 | results_rv64imv | Dilithium2 | Keypair | 462,304 | 450,492 | +11,812 | +2.56 % |
| Dilithium/RV64 | results_rv64imv | Dilithium2 | Sign with rand | 1,552,215 | 1,495,463 | +56,752 | +3.66 % |
| Dilithium/RV64 | results_rv64imv | Dilithium2 | Verify | 491,465 | 473,733 | +17,732 | +3.61 % |
| Dilithium/RV64 | results_rv64imv | Dilithium3 | Keypair | 807,055 | 785,265 | +21,790 | +2.70 % |
| Dilithium/RV64 | results_rv64imv | Dilithium3 | Sign with rand | 2,394,665 | 2,296,745 | +97,920 | +4.09 % |
| Dilithium/RV64 | results_rv64imv | Dilithium3 | Verify | 795,018 | 768,561 | +26,457 | +3.33 % |
| Dilithium/RV64 | results_rv64imv | Dilithium5 | Keypair | 1,343,662 | 1,304,667 | +38,995 | +2.90 % |
| Dilithium/RV64 | results_rv64imv | Dilithium5 | Sign with rand | 3,059,716 | 2,962,022 | +97,694 | +3.19 % |
| Dilithium/RV64 | results_rv64imv | Dilithium5 | Verify | 1,342,645 | 1,309,333 | +33,312 | +2.48 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium2 | Keypair | 374,590 | 360,605 | +13,985 | +3.73 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium2 | Sign with rand | 1,385,100 | 1,325,889 | +59,211 | +4.27 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium2 | Verify | 403,226 | 388,393 | +14,833 | +3.68 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium3 | Keypair | 641,575 | 623,458 | +18,117 | +2.82 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium3 | Sign with rand | 2,141,780 | 2,062,203 | +79,577 | +3.72 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium3 | Verify | 640,749 | 619,701 | +21,048 | +3.28 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium5 | Keypair | 1,058,104 | 1,025,191 | +32,913 | +3.11 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium5 | Sign with rand | 2,658,258 | 2,560,067 | +98,191 | +3.69 % |
| Dilithium/RV64 | results_rv64imbv | Dilithium5 | Verify | 1,077,474 | 1,040,081 | +37,393 | +3.47 % |
| Kyber/RV64 | results_c908_rv64im | Kyber512 | kyber_keypair | 168,576 | 162,978 | +5,598 | +3.32 % |
| Kyber/RV64 | results_c908_rv64im | Kyber512 | kyber_encaps | 181,701 | 175,540 | +6,161 | +3.39 % |
| Kyber/RV64 | results_c908_rv64im | Kyber512 | kyber_decaps | 232,109 | 225,528 | +6,581 | +2.84 % |
| Kyber/RV64 | results_c908_rv64im | Kyber768 | kyber_keypair | 276,641 | 270,293 | +6,348 | +2.29 % |
| Kyber/RV64 | results_c908_rv64im | Kyber768 | kyber_encaps | 296,989 | 286,568 | +10,421 | +3.51 % |
| Kyber/RV64 | results_c908_rv64im | Kyber768 | kyber_decaps | 362,763 | 352,295 | +10,468 | +2.89 % |
| Kyber/RV64 | results_c908_rv64im | Kyber1024 | kyber_keypair | 426,666 | 408,185 | +18,481 | +4.33 % |
| Kyber/RV64 | results_c908_rv64im | Kyber1024 | kyber_encaps | 442,808 | 427,724 | +15,084 | +3.41 % |
| Kyber/RV64 | results_c908_rv64im | Kyber1024 | kyber_decaps | 530,189 | 508,447 | +21,742 | +4.10 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber512 | kyber_keypair | 143,795 | 138,990 | +4,805 | +3.34 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber512 | kyber_encaps | 158,772 | 153,238 | +5,534 | +3.49 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber512 | kyber_decaps | 209,927 | 204,135 | +5,792 | +2.76 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber768 | kyber_keypair | 236,513 | 234,415 | +2,098 | +0.89 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber768 | kyber_encaps | 253,766 | 250,070 | +3,696 | +1.46 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber768 | kyber_decaps | 325,582 | 318,676 | +6,906 | +2.12 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber1024 | kyber_keypair | 355,022 | 354,188 | +834 | +0.23 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber1024 | kyber_encaps | 373,876 | 370,981 | +2,895 | +0.77 % |
| Kyber/RV64 | results_c908_rv64imb | Kyber1024 | kyber_decaps | 459,318 | 453,658 | +5,660 | +1.23 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber512 | kyber_keypair | 123,951 | 118,865 | +5,086 | +4.10 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber512 | kyber_encaps | 129,386 | 124,229 | +5,157 | +3.99 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber512 | kyber_decaps | 159,597 | 153,865 | +5,732 | +3.59 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber768 | kyber_keypair | 197,300 | 191,845 | +5,455 | +2.76 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber768 | kyber_encaps | 207,640 | 202,687 | +4,953 | +2.39 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber768 | kyber_decaps | 247,416 | 240,200 | +7,216 | +2.92 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber1024 | kyber_keypair | 306,973 | 296,102 | +10,871 | +3.54 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber1024 | kyber_encaps | 316,127 | 304,995 | +11,132 | +3.52 % |
| Kyber/RV64 | results_c908_rv64imv | Kyber1024 | kyber_decaps | 366,081 | 352,814 | +13,267 | +3.62 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber512 | kyber_keypair | 98,370 | 95,678 | +2,692 | +2.74 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber512 | kyber_encaps | 107,245 | 102,496 | +4,749 | +4.43 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber512 | kyber_decaps | 137,975 | 132,842 | +5,133 | +3.72 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber768 | kyber_keypair | 159,433 | 154,291 | +5,142 | +3.23 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber768 | kyber_encaps | 169,876 | 164,770 | +5,106 | +3.01 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber768 | kyber_decaps | 211,364 | 204,564 | +6,800 | +3.22 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber1024 | kyber_keypair | 242,752 | 237,332 | +5,420 | +2.23 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber1024 | kyber_encaps | 254,146 | 247,397 | +6,749 | +2.66 % |
| Kyber/RV64 | results_c908_rv64imbv | Kyber1024 | kyber_decaps | 311,392 | 298,043 | +13,349 | +4.29 % |

Top-level operations: mean relative speedup **+3.11 %** (range +0.23 % … +4.43 %).

## `Dilithium/RV64`

### `results_rv64im.txt`

#### Dilithium2

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 277,606 | 272,073 | **+5,533** | **+1.99 %** |
| polyvecl_uniform_eta | 34,936 | 34,780 | +156 | +0.45 % |
| polyveck_uniform_eta | 34,934 | 34,808 | +126 | +0.36 % |
| poly_ntt | 8,260 | 8,260 | +0 | +0.00 % |
| poly_intt | 8,486 | 8,486 | +0 | +0.00 % |
| poly_pointwise | 2,320 | 2,322 | -2 | -0.09 % |
| polyveck_pointwise_poly | 10,117 | 10,116 | +1 | +0.01 % |
| polyvec_matrix_pointwise | 25,619 | 25,414 | +205 | +0.80 % |
| polyveck_reduce | 6,439 | 6,441 | -2 | -0.03 % |
| poly_challenge | 3,776 | 3,780 | -4 | -0.11 % |
| Keypair | 538,426 | 519,986 | **+18,440** | **+3.42 %** |
| Sign with rand | 2,123,775 | 2,038,452 | **+85,323** | **+4.02 %** |
| Verify | 588,395 | 571,807 | **+16,588** | **+2.82 %** |

#### Dilithium3

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 523,054 | 510,698 | **+12,356** | **+2.36 %** |
| polyvecl_uniform_eta | 50,457 | 51,285 | **-828** | **-1.64 %** |
| polyveck_uniform_eta | 61,066 | 62,193 | **-1,127** | **-1.85 %** |
| poly_ntt | 8,260 | 8,260 | +0 | +0.00 % |
| poly_intt | 8,486 | 8,486 | +0 | +0.00 % |
| poly_pointwise | 2,320 | 2,320 | +0 | +0.00 % |
| polyveck_pointwise_poly | 15,308 | 15,307 | +1 | +0.01 % |
| polyvec_matrix_pointwise | 55,171 | 55,637 | -466 | -0.84 % |
| polyveck_reduce | 9,643 | 9,643 | +0 | +0.00 % |
| poly_challenge | 3,966 | 3,964 | +2 | +0.05 % |
| Keypair | 919,823 | 894,817 | **+25,006** | **+2.72 %** |
| Sign with rand | 3,332,922 | 3,238,436 | **+94,486** | **+2.83 %** |
| Verify | 938,862 | 912,327 | **+26,535** | **+2.83 %** |

#### Dilithium5

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 974,548 | 952,000 | **+22,548** | **+2.31 %** |
| polyvecl_uniform_eta | 58,178 | 57,935 | +243 | +0.42 % |
| polyveck_uniform_eta | 67,795 | 67,487 | +308 | +0.45 % |
| poly_ntt | 8,260 | 8,260 | +0 | +0.00 % |
| poly_intt | 8,488 | 8,486 | +2 | +0.02 % |
| poly_pointwise | 2,320 | 2,320 | +0 | +0.00 % |
| polyveck_pointwise_poly | 20,215 | 20,213 | +2 | +0.01 % |
| polyvec_matrix_pointwise | 102,419 | 104,152 | **-1,733** | **-1.69 %** |
| polyveck_reduce | 12,851 | 12,851 | +0 | +0.00 % |
| poly_challenge | 4,162 | 4,166 | -4 | -0.10 % |
| Keypair | 1,499,165 | 1,455,064 | **+44,101** | **+2.94 %** |
| Sign with rand | 4,106,997 | 3,953,280 | **+153,717** | **+3.74 %** |
| Verify | 1,553,779 | 1,504,774 | **+49,005** | **+3.15 %** |

### `results_rv64imb.txt`

#### Dilithium2

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 207,094 | 203,198 | **+3,896** | **+1.88 %** |
| polyvecl_uniform_eta | 29,515 | 29,570 | -55 | -0.19 % |
| polyveck_uniform_eta | 29,532 | 29,525 | +7 | +0.02 % |
| poly_ntt | 8,260 | 8,260 | +0 | +0.00 % |
| poly_intt | 8,486 | 8,486 | +0 | +0.00 % |
| poly_pointwise | 2,320 | 2,320 | +0 | +0.00 % |
| polyveck_pointwise_poly | 10,117 | 10,116 | +1 | +0.01 % |
| polyvec_matrix_pointwise | 25,592 | 25,406 | +186 | +0.73 % |
| polyveck_reduce | 6,439 | 6,440 | -1 | -0.02 % |
| poly_challenge | 2,910 | 2,912 | -2 | -0.07 % |
| Keypair | 448,575 | 431,087 | **+17,488** | **+3.90 %** |
| Sign with rand | 1,939,463 | 1,888,715 | **+50,748** | **+2.62 %** |
| Verify | 503,871 | 486,812 | **+17,059** | **+3.39 %** |

#### Dilithium3

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 389,574 | 380,231 | **+9,343** | **+2.40 %** |
| polyvecl_uniform_eta | 44,727 | 43,118 | **+1,609** | **+3.60 %** |
| polyveck_uniform_eta | 54,385 | 52,336 | **+2,049** | **+3.77 %** |
| poly_ntt | 8,260 | 8,260 | +0 | +0.00 % |
| poly_intt | 8,486 | 8,486 | +0 | +0.00 % |
| poly_pointwise | 2,320 | 2,320 | +0 | +0.00 % |
| polyveck_pointwise_poly | 15,308 | 15,307 | +1 | +0.01 % |
| polyvec_matrix_pointwise | 55,772 | 55,803 | -31 | -0.06 % |
| polyveck_reduce | 9,643 | 9,643 | +0 | +0.00 % |
| poly_challenge | 3,071 | 3,062 | +9 | +0.29 % |
| Keypair | 753,005 | 731,649 | **+21,356** | **+2.84 %** |
| Sign with rand | 3,085,235 | 2,985,823 | **+99,412** | **+3.22 %** |
| Verify | 790,796 | 763,777 | **+27,019** | **+3.42 %** |

#### Dilithium5

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 726,801 | 710,721 | **+16,080** | **+2.21 %** |
| polyvecl_uniform_eta | 49,758 | 49,831 | -73 | -0.15 % |
| polyveck_uniform_eta | 57,747 | 57,867 | -120 | -0.21 % |
| poly_ntt | 8,265 | 8,260 | +5 | +0.06 % |
| poly_intt | 8,486 | 8,486 | +0 | +0.00 % |
| poly_pointwise | 2,320 | 2,320 | +0 | +0.00 % |
| polyveck_pointwise_poly | 20,215 | 20,213 | +2 | +0.01 % |
| polyvec_matrix_pointwise | 101,683 | 107,370 | **-5,687** | **-5.59 %** |
| polyveck_reduce | 12,851 | 12,851 | +0 | +0.00 % |
| poly_challenge | 3,225 | 3,224 | +1 | +0.03 % |
| Keypair | 1,216,507 | 1,180,977 | **+35,530** | **+2.92 %** |
| Sign with rand | 3,700,091 | 3,578,512 | **+121,579** | **+3.29 %** |
| Verify | 1,283,450 | 1,243,679 | **+39,771** | **+3.10 %** |

### `results_rv64imv.txt`

#### Dilithium2

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 270,753 | 265,192 | **+5,561** | **+2.05 %** |
| polyveclk_uniform_eta | 54,823 | 54,823 | +0 | +0.00 % |
| poly_ntt | 3,329 | 3,329 | +0 | +0.00 % |
| poly_intt | 3,492 | 3,492 | +0 | +0.00 % |
| poly_pointwise | 670 | 664 | +6 | +0.90 % |
| polyveck_pointwise_poly | 2,680 | 2,682 | -2 | -0.07 % |
| polyvec_matrix_pointwise | 12,404 | 12,412 | -8 | -0.06 % |
| polyveck_reduce | 2,080 | 2,092 | -12 | -0.58 % |
| poly_challenge | 3,779 | 3,775 | +4 | +0.11 % |
| Keypair | 462,304 | 450,492 | **+11,812** | **+2.56 %** |
| Sign with rand | 1,552,215 | 1,495,463 | **+56,752** | **+3.66 %** |
| Verify | 491,465 | 473,733 | **+17,732** | **+3.61 %** |

#### Dilithium3

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 512,706 | 500,047 | **+12,659** | **+2.47 %** |
| polyveclk_uniform_eta | 91,992 | 91,681 | +311 | +0.34 % |
| poly_ntt | 3,329 | 3,329 | +0 | +0.00 % |
| poly_intt | 3,492 | 3,492 | +0 | +0.00 % |
| poly_pointwise | 666 | 662 | +4 | +0.60 % |
| polyveck_pointwise_poly | 4,005 | 4,009 | -4 | -0.10 % |
| polyvec_matrix_pointwise | 30,222 | 30,955 | **-733** | **-2.43 %** |
| polyveck_reduce | 2,971 | 2,998 | -27 | -0.91 % |
| poly_challenge | 3,963 | 3,960 | +3 | +0.08 % |
| Keypair | 807,055 | 785,265 | **+21,790** | **+2.70 %** |
| Sign with rand | 2,394,665 | 2,296,745 | **+97,920** | **+4.09 %** |
| Verify | 795,018 | 768,561 | **+26,457** | **+3.33 %** |

#### Dilithium5

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 960,082 | 933,981 | **+26,101** | **+2.72 %** |
| polyveclk_uniform_eta | 106,051 | 101,660 | **+4,391** | **+4.14 %** |
| poly_ntt | 3,329 | 3,329 | +0 | +0.00 % |
| poly_intt | 3,492 | 3,492 | +0 | +0.00 % |
| poly_pointwise | 668 | 664 | +4 | +0.60 % |
| polyveck_pointwise_poly | 5,328 | 5,332 | -4 | -0.08 % |
| polyvec_matrix_pointwise | 62,314 | 62,815 | -501 | -0.80 % |
| polyveck_reduce | 3,941 | 3,970 | -29 | -0.74 % |
| poly_challenge | 4,164 | 4,165 | -1 | -0.02 % |
| Keypair | 1,343,662 | 1,304,667 | **+38,995** | **+2.90 %** |
| Sign with rand | 3,059,716 | 2,962,022 | **+97,694** | **+3.19 %** |
| Verify | 1,342,645 | 1,309,333 | **+33,312** | **+2.48 %** |

### `results_rv64imbv.txt`

#### Dilithium2

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 199,878 | 195,894 | **+3,984** | **+1.99 %** |
| polyveclk_uniform_eta | 45,022 | 45,011 | +11 | +0.02 % |
| poly_ntt | 3,329 | 3,329 | +0 | +0.00 % |
| poly_intt | 3,492 | 3,492 | +0 | +0.00 % |
| poly_pointwise | 674 | 664 | **+10** | **+1.48 %** |
| polyveck_pointwise_poly | 2,688 | 2,688 | +0 | +0.00 % |
| polyvec_matrix_pointwise | 12,410 | 12,410 | +0 | +0.00 % |
| polyveck_reduce | 2,069 | 2,069 | +0 | +0.00 % |
| poly_challenge | 2,913 | 2,910 | +3 | +0.10 % |
| Keypair | 374,590 | 360,605 | **+13,985** | **+3.73 %** |
| Sign with rand | 1,385,100 | 1,325,889 | **+59,211** | **+4.27 %** |
| Verify | 403,226 | 388,393 | **+14,833** | **+3.68 %** |

#### Dilithium3

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 380,918 | 369,403 | **+11,515** | **+3.02 %** |
| polyveclk_uniform_eta | 75,388 | 75,793 | -405 | -0.54 % |
| poly_ntt | 3,329 | 3,329 | +0 | +0.00 % |
| poly_intt | 3,492 | 3,492 | +0 | +0.00 % |
| poly_pointwise | 666 | 667 | -1 | -0.15 % |
| polyveck_pointwise_poly | 4,019 | 4,019 | +0 | +0.00 % |
| polyvec_matrix_pointwise | 31,200 | 30,134 | **+1,066** | **+3.42 %** |
| polyveck_reduce | 2,971 | 2,972 | -1 | -0.03 % |
| poly_challenge | 3,062 | 3,067 | -5 | -0.16 % |
| Keypair | 641,575 | 623,458 | **+18,117** | **+2.82 %** |
| Sign with rand | 2,141,780 | 2,062,203 | **+79,577** | **+3.72 %** |
| Verify | 640,749 | 619,701 | **+21,048** | **+3.28 %** |

#### Dilithium5

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| polyvec_matrix_expand | 712,247 | 689,527 | **+22,720** | **+3.19 %** |
| polyveclk_uniform_eta | 83,559 | 83,565 | -6 | -0.01 % |
| poly_ntt | 3,329 | 3,329 | +0 | +0.00 % |
| poly_intt | 3,492 | 3,492 | +0 | +0.00 % |
| poly_pointwise | 673 | 676 | -3 | -0.45 % |
| polyveck_pointwise_poly | 5,346 | 5,346 | +0 | +0.00 % |
| polyvec_matrix_pointwise | 61,162 | 63,282 | **-2,120** | **-3.47 %** |
| polyveck_reduce | 3,933 | 3,935 | -2 | -0.05 % |
| poly_challenge | 3,243 | 3,227 | +16 | +0.49 % |
| Keypair | 1,058,104 | 1,025,191 | **+32,913** | **+3.11 %** |
| Sign with rand | 2,658,258 | 2,560,067 | **+98,191** | **+3.69 %** |
| Verify | 1,077,474 | 1,040,081 | **+37,393** | **+3.47 %** |

## `Kyber/RV64`

### `results_c908_rv64im.txt`

#### Kyber512

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 47,526 | 46,693 | **+833** | **+1.75 %** |
| poly_getnoise_eta1 | 7,840 | 7,842 | -2 | -0.03 % |
| NTT | 6,610 | 6,610 | +0 | +0.00 % |
| INVNTT | 6,997 | 6,997 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 2,669 | 2,669 | +0 | +0.00 % |
| poly_basemul_acc_cached | 2,123 | 2,123 | +0 | +0.00 % |
| poly_basemul_acc_cache_end | 3,246 | 3,246 | +0 | +0.00 % |
| polyvec_basemul_acc | 6,550 | 6,552 | -2 | -0.03 % |
| matrix-vector mul | 13,103 | 13,107 | -4 | -0.03 % |
| kyber_keypair | 168,576 | 162,978 | **+5,598** | **+3.32 %** |
| kyber_encaps | 181,701 | 175,540 | **+6,161** | **+3.39 %** |
| kyber_decaps | 232,109 | 225,528 | **+6,581** | **+2.84 %** |

#### Kyber768

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 112,017 | 107,424 | **+4,593** | **+4.10 %** |
| poly_getnoise_eta1 | 5,600 | 5,602 | -2 | -0.04 % |
| NTT | 6,596 | 6,596 | +0 | +0.00 % |
| INVNTT | 6,982 | 6,982 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 2,667 | 2,667 | +0 | +0.00 % |
| poly_basemul_acc_cached | 2,122 | 2,122 | +0 | +0.00 % |
| poly_basemul_acc_cache_end | 3,244 | 3,244 | +0 | +0.00 % |
| polyvec_basemul_acc | 9,180 | 9,182 | -2 | -0.02 % |
| matrix-vector mul | 27,528 | 27,531 | -3 | -0.01 % |
| kyber_keypair | 276,641 | 270,293 | **+6,348** | **+2.29 %** |
| kyber_encaps | 296,989 | 286,568 | **+10,421** | **+3.51 %** |
| kyber_decaps | 362,763 | 352,295 | **+10,468** | **+2.89 %** |

#### Kyber1024

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 196,474 | 192,636 | **+3,838** | **+1.95 %** |
| poly_getnoise_eta1 | 5,601 | 5,605 | -4 | -0.07 % |
| NTT | 6,610 | 6,594 | +16 | +0.24 % |
| INVNTT | 6,997 | 6,981 | +16 | +0.23 % |
| poly_basemul_acc_cache_init | 2,667 | 2,667 | +0 | +0.00 % |
| poly_basemul_acc_cached | 2,122 | 2,122 | +0 | +0.00 % |
| poly_basemul_acc_cache_end | 3,244 | 3,244 | +0 | +0.00 % |
| polyvec_basemul_acc | 11,821 | 11,822 | -1 | -0.01 % |
| matrix-vector mul | 47,339 | 47,294 | +45 | +0.10 % |
| kyber_keypair | 426,666 | 408,185 | **+18,481** | **+4.33 %** |
| kyber_encaps | 442,808 | 427,724 | **+15,084** | **+3.41 %** |
| kyber_decaps | 530,189 | 508,447 | **+21,742** | **+4.10 %** |

### `results_c908_rv64imb.txt`

#### Kyber512

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 36,572 | 36,347 | +225 | +0.62 % |
| poly_getnoise_eta1 | 6,211 | 6,218 | -7 | -0.11 % |
| NTT | 6,596 | 6,596 | +0 | +0.00 % |
| INVNTT | 6,982 | 6,982 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 2,669 | 2,669 | +0 | +0.00 % |
| poly_basemul_acc_cached | 2,123 | 2,123 | +0 | +0.00 % |
| poly_basemul_acc_cache_end | 3,246 | 3,246 | +0 | +0.00 % |
| polyvec_basemul_acc | 6,551 | 6,551 | +0 | +0.00 % |
| matrix-vector mul | 13,105 | 13,105 | +0 | +0.00 % |
| kyber_keypair | 143,795 | 138,990 | **+4,805** | **+3.34 %** |
| kyber_encaps | 158,772 | 153,238 | **+5,534** | **+3.49 %** |
| kyber_decaps | 209,927 | 204,135 | **+5,792** | **+2.76 %** |

#### Kyber768

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 84,328 | 86,128 | **-1,800** | **-2.13 %** |
| poly_getnoise_eta1 | 4,713 | 4,720 | -7 | -0.15 % |
| NTT | 6,580 | 6,580 | +0 | +0.00 % |
| INVNTT | 6,966 | 6,966 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 2,667 | 2,667 | +0 | +0.00 % |
| poly_basemul_acc_cached | 2,122 | 2,122 | +0 | +0.00 % |
| poly_basemul_acc_cache_end | 3,244 | 3,244 | +0 | +0.00 % |
| polyvec_basemul_acc | 9,180 | 9,181 | -1 | -0.01 % |
| matrix-vector mul | 27,528 | 27,525 | +3 | +0.01 % |
| kyber_keypair | 236,513 | 234,415 | +2,098 | +0.89 % |
| kyber_encaps | 253,766 | 250,070 | **+3,696** | **+1.46 %** |
| kyber_decaps | 325,582 | 318,676 | **+6,906** | **+2.12 %** |

#### Kyber1024

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 160,321 | 150,399 | **+9,922** | **+6.19 %** |
| poly_getnoise_eta1 | 4,719 | 4,711 | +8 | +0.17 % |
| NTT | 6,610 | 6,610 | +0 | +0.00 % |
| INVNTT | 6,997 | 6,997 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 2,667 | 2,667 | +0 | +0.00 % |
| poly_basemul_acc_cached | 2,122 | 2,122 | +0 | +0.00 % |
| poly_basemul_acc_cache_end | 3,244 | 3,244 | +0 | +0.00 % |
| polyvec_basemul_acc | 11,821 | 11,822 | -1 | -0.01 % |
| matrix-vector mul | 47,315 | 47,299 | +16 | +0.03 % |
| kyber_keypair | 355,022 | 354,188 | +834 | +0.23 % |
| kyber_encaps | 373,876 | 370,981 | +2,895 | +0.77 % |
| kyber_decaps | 459,318 | 453,658 | **+5,660** | **+1.23 %** |

### `results_c908_rv64imv.txt`

#### Kyber512

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 40,279 | 40,258 | +21 | +0.05 % |
| poly_getnoise_eta1 | 7,256 | 7,252 | +4 | +0.06 % |
| NTT | 1,585 | 1,585 | +0 | +0.00 % |
| INVNTT | 1,827 | 1,826 | +1 | +0.05 % |
| poly_basemul_acc | 812 | 791 | **+21** | **+2.59 %** |
| poly_basemul_acc_cache_init | 842 | 828 | **+14** | **+1.66 %** |
| poly_basemul_cached | 615 | 615 | +0 | +0.00 % |
| poly_basemul_acc_cached | 711 | 711 | +0 | +0.00 % |
| polyvec_basemul_acc | 1,532 | 1,488 | **+44** | **+2.87 %** |
| matrix-vector mul | 2,890 | 2,890 | +0 | +0.00 % |
| polyvec_basemul_acc_cached | 1,329 | 1,329 | +0 | +0.00 % |
| kyber_keypair | 123,951 | 118,865 | **+5,086** | **+4.10 %** |
| kyber_encaps | 129,386 | 124,229 | **+5,157** | **+3.99 %** |
| kyber_decaps | 159,597 | 153,865 | **+5,732** | **+3.59 %** |

#### Kyber768

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 90,750 | 90,424 | +326 | +0.36 % |
| poly_getnoise_eta1 | 4,794 | 4,789 | +5 | +0.10 % |
| NTT | 1,585 | 1,585 | +0 | +0.00 % |
| INVNTT | 1,825 | 1,824 | +1 | +0.05 % |
| poly_basemul_acc | 790 | 789 | +1 | +0.13 % |
| poly_basemul_acc_cache_init | 827 | 826 | +1 | +0.12 % |
| poly_basemul_cached | 614 | 613 | +1 | +0.16 % |
| poly_basemul_acc_cached | 710 | 709 | +1 | +0.14 % |
| polyvec_basemul_acc | 2,272 | 2,272 | +0 | +0.00 % |
| matrix-vector mul | 6,462 | 6,459 | +3 | +0.05 % |
| polyvec_basemul_acc_cached | 2,044 | 2,043 | +1 | +0.05 % |
| kyber_keypair | 197,300 | 191,845 | **+5,455** | **+2.76 %** |
| kyber_encaps | 207,640 | 202,687 | **+4,953** | **+2.39 %** |
| kyber_decaps | 247,416 | 240,200 | **+7,216** | **+2.92 %** |

#### Kyber1024

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 165,129 | 160,584 | **+4,545** | **+2.75 %** |
| poly_getnoise_eta1 | 4,782 | 4,791 | -9 | -0.19 % |
| NTT | 1,585 | 1,585 | +0 | +0.00 % |
| INVNTT | 1,826 | 1,827 | -1 | -0.05 % |
| poly_basemul_acc | 789 | 789 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 826 | 826 | +0 | +0.00 % |
| poly_basemul_cached | 613 | 613 | +0 | +0.00 % |
| poly_basemul_acc_cached | 709 | 709 | +0 | +0.00 % |
| polyvec_basemul_acc | 3,063 | 3,063 | +0 | +0.00 % |
| matrix-vector mul | 11,461 | 11,463 | -2 | -0.02 % |
| polyvec_basemul_acc_cached | 2,750 | 2,750 | +0 | +0.00 % |
| kyber_keypair | 306,973 | 296,102 | **+10,871** | **+3.54 %** |
| kyber_encaps | 316,127 | 304,995 | **+11,132** | **+3.52 %** |
| kyber_decaps | 366,081 | 352,814 | **+13,267** | **+3.62 %** |

### `results_c908_rv64imbv.txt`

#### Kyber512

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 30,458 | 30,531 | -73 | -0.24 % |
| poly_getnoise_eta1 | 5,619 | 5,616 | +3 | +0.05 % |
| NTT | 1,585 | 1,585 | +0 | +0.00 % |
| INVNTT | 1,826 | 1,827 | -1 | -0.05 % |
| poly_basemul_acc | 791 | 791 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 828 | 828 | +0 | +0.00 % |
| poly_basemul_cached | 615 | 615 | +0 | +0.00 % |
| poly_basemul_acc_cached | 711 | 711 | +0 | +0.00 % |
| polyvec_basemul_acc | 1,488 | 1,488 | +0 | +0.00 % |
| matrix-vector mul | 2,890 | 2,890 | +0 | +0.00 % |
| polyvec_basemul_acc_cached | 1,329 | 1,329 | +0 | +0.00 % |
| kyber_keypair | 98,370 | 95,678 | **+2,692** | **+2.74 %** |
| kyber_encaps | 107,245 | 102,496 | **+4,749** | **+4.43 %** |
| kyber_decaps | 137,975 | 132,842 | **+5,133** | **+3.72 %** |

#### Kyber768

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 68,403 | 68,550 | -147 | -0.21 % |
| poly_getnoise_eta1 | 3,896 | 3,901 | -5 | -0.13 % |
| NTT | 1,585 | 1,585 | +0 | +0.00 % |
| INVNTT | 1,825 | 1,824 | +1 | +0.05 % |
| poly_basemul_acc | 790 | 789 | +1 | +0.13 % |
| poly_basemul_acc_cache_init | 827 | 826 | +1 | +0.12 % |
| poly_basemul_cached | 614 | 613 | +1 | +0.16 % |
| poly_basemul_acc_cached | 710 | 709 | +1 | +0.14 % |
| polyvec_basemul_acc | 2,272 | 2,272 | +0 | +0.00 % |
| matrix-vector mul | 6,462 | 6,459 | +3 | +0.05 % |
| polyvec_basemul_acc_cached | 2,044 | 2,043 | +1 | +0.05 % |
| kyber_keypair | 159,433 | 154,291 | **+5,142** | **+3.23 %** |
| kyber_encaps | 169,876 | 164,770 | **+5,106** | **+3.01 %** |
| kyber_decaps | 211,364 | 204,564 | **+6,800** | **+3.22 %** |

#### Kyber1024

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| gen_a | 125,934 | 121,829 | **+4,105** | **+3.26 %** |
| poly_getnoise_eta1 | 3,900 | 3,900 | +0 | +0.00 % |
| NTT | 1,586 | 1,585 | +1 | +0.06 % |
| INVNTT | 1,827 | 1,826 | +1 | +0.05 % |
| poly_basemul_acc | 789 | 789 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 826 | 826 | +0 | +0.00 % |
| poly_basemul_cached | 613 | 613 | +0 | +0.00 % |
| poly_basemul_acc_cached | 709 | 709 | +0 | +0.00 % |
| polyvec_basemul_acc | 3,063 | 3,063 | +0 | +0.00 % |
| matrix-vector mul | 11,461 | 11,462 | -1 | -0.01 % |
| polyvec_basemul_acc_cached | 2,750 | 2,750 | +0 | +0.00 % |
| kyber_keypair | 242,752 | 237,332 | **+5,420** | **+2.23 %** |
| kyber_encaps | 254,146 | 247,397 | **+6,749** | **+2.66 %** |
| kyber_decaps | 311,392 | 298,043 | **+13,349** | **+4.29 %** |

## `ntt`

### `speed_ntt_c908.txt`

#### speed_singleissue_kyber_plantard_ntt_rv32 — Kyber 7-layer NTT & Plantard based & 4+3 layers merging & RV32IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 13,218 | 13,218 | +0 | +0.00 % |
| intt | 11,427 | 11,427 | +0 | +0.00 % |
| basemul_acc | 4,171 | 4,171 | +0 | +0.00 % |
| basemul_acc_end | 7,120 | 7,120 | +0 | +0.00 % |
| basemul_cache_init | 3,916 | 3,916 | +0 | +0.00 % |
| basemul_acc_cache_init | 4,172 | 4,172 | +0 | +0.00 % |
| basemul_acc_cache_init_end | 7,121 | 7,121 | +0 | +0.00 % |
| basemul_acc_cached | 2,891 | 2,891 | +0 | +0.00 % |
| basemul_acc_cache_end | 5,900 | 5,900 | +0 | +0.00 % |
| plantard_rdc | 2,841 | 2,841 | +0 | +0.00 % |
| toplant | 2,841 | 2,841 | +0 | +0.00 % |

#### speed_dualissue_kyber_plantard_ntt_rv32 — Kyber 7-layer NTT & Plantard based & 4+3 layers merging & RV32IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 5,714 | 5,728 | -14 | -0.25 % |
| intt | 6,005 | 6,017 | -12 | -0.20 % |
| basemul_acc | 2,057 | 2,057 | +0 | +0.00 % |
| basemul_acc_end | 3,053 | 3,053 | +0 | +0.00 % |
| basemul_cache_init | 1,962 | 1,962 | +0 | +0.00 % |
| basemul_acc_cache_init | 2,218 | 2,218 | +0 | +0.00 % |
| basemul_acc_cache_init_end | 3,340 | 3,340 | +0 | +0.00 % |
| basemul_acc_cached | 1,674 | 1,674 | +0 | +0.00 % |
| basemul_acc_cache_end | 2,668 | 2,668 | +0 | +0.00 % |
| plantard_rdc | 1,339 | 1,339 | +0 | +0.00 % |
| toplant | 1,339 | 1,339 | +0 | +0.00 % |

#### speed_singleissue_kyber_plantard_ntt_rv64 — Kyber 7-layer NTT & Plantard based & 4+3 layers merging & RV64IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 15,010 | 15,010 | +0 | +0.00 % |
| intt | 13,444 | 13,444 | +0 | +0.00 % |
| basemul_acc | 4,941 | 4,941 | +0 | +0.00 % |
| basemul_acc_end | 8,279 | 8,279 | +0 | +0.00 % |
| basemul_cache_init | 4,685 | 4,685 | +0 | +0.00 % |
| basemul_acc_cache_init | 4,941 | 4,941 | +0 | +0.00 % |
| basemul_acc_cache_init_end | 8,344 | 8,344 | +0 | +0.00 % |
| basemul_acc_cached | 3,404 | 3,404 | +0 | +0.00 % |
| basemul_acc_cache_end | 6,868 | 6,868 | +0 | +0.00 % |
| plantard_rdc | 3,293 | 3,293 | +0 | +0.00 % |
| toplant | 3,295 | 3,295 | +0 | +0.00 % |

#### speed_dualissue_kyber_plantard_ntt_rv64 — Kyber 7-layer NTT & Plantard based & 4+3 layers merging & RV64IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 6,609 | 6,579 | +30 | +0.45 % |
| intt | 6,996 | 6,965 | +31 | +0.44 % |
| basemul_acc | 2,635 | 2,635 | +0 | +0.00 % |
| basemul_acc_end | 3,757 | 3,757 | +0 | +0.00 % |
| basemul_cache_init | 2,507 | 2,507 | +0 | +0.00 % |
| basemul_acc_cache_init | 2,667 | 2,667 | +0 | +0.00 % |
| basemul_acc_cache_init_end | 4,172 | 4,172 | +0 | +0.00 % |
| basemul_acc_cached | 2,122 | 2,122 | +0 | +0.00 % |
| basemul_acc_cache_end | 3,245 | 3,245 | +0 | +0.00 % |
| plantard_rdc | 1,532 | 1,532 | +0 | +0.00 % |
| toplant | 1,534 | 1,534 | +0 | +0.00 % |

#### speed_dualissue_kyber_plantard_l32_ntt_rv64 — Kyber 7-layer NTT & Plantard based & 4+3 layers merging & RV64IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 7,281 | 7,251 | +30 | +0.41 % |
| intt | 7,668 | 7,637 | +31 | +0.40 % |
| basemul_acc | 2,763 | 2,763 | +0 | +0.00 % |
| basemul_acc_end | 3,987 | 3,987 | +0 | +0.00 % |
| basemul_cache_init | 2,635 | 2,635 | +0 | +0.00 % |
| basemul_acc_cache_init | 2,795 | 2,795 | +0 | +0.00 % |
| basemul_acc_cache_init_end | 4,498 | 4,498 | +0 | +0.00 % |
| basemul_acc_cached | 2,122 | 2,122 | +0 | +0.00 % |
| basemul_acc_cache_end | 3,347 | 3,347 | +0 | +0.00 % |
| plantard_rdc | 1,760 | 1,760 | +0 | +0.00 % |
| toplant | 1,762 | 1,762 | +0 | +0.00 % |

#### speed_dualissue_kyber_mont_ntt_rv32 — Kyber 7-layer NTT & Mont based & 1+3+3 layers merging & RV32IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 6,442 | 6,442 | +0 | +0.00 % |
| intt | 7,192 | 7,192 | +0 | +0.00 % |

#### speed_dualissue_kyber_mont_ntt_rvv — Kyber 7-layer NTT & Montgomery based & RVV with VLEN128

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 1,581 | 1,577 | +4 | +0.25 % |
| intt | 1,816 | 1,817 | -1 | -0.06 % |
| poly_basemul | 686 | 686 | +0 | +0.00 % |
| poly_basemul_acc | 782 | 782 | +0 | +0.00 % |
| poly_basemul_cache_init | 723 | 723 | +0 | +0.00 % |
| poly_basemul_acc_cache_init | 819 | 819 | +0 | +0.00 % |
| poly_basemul_cached | 606 | 606 | +0 | +0.00 % |
| poly_basemul_acc_cached | 702 | 702 | +0 | +0.00 % |
| poly_reduce | 269 | 267 | +2 | +0.74 % |
| poly_tomont | 252 | 250 | +2 | +0.79 % |
| ntt2normal_order | 713 | 713 | +0 | +0.00 % |
| normal2ntt_order | 701 | 701 | +0 | +0.00 % |

#### speed_singleissue_dilithium_mont_ntt_rv32 — Dilithium 8-layer NTT & Montgomery based & 3+3+2 layers merging & RV32IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 13,223 | 13,223 | +0 | +0.00 % |
| poly_basemul_init | 1,035 | 1,035 | +0 | +0.00 % |
| poly_basemul_acc | 1,933 | 1,933 | +0 | +0.00 % |
| poly_basemul_acc_end | 3,787 | 3,787 | +0 | +0.00 % |
| poly_basemul | 2,856 | 2,856 | +0 | +0.00 % |
| poly_reduce | 1,226 | 1,226 | +0 | +0.00 % |
| intt | 11,114 | 11,114 | +0 | +0.00 % |

#### speed_dualissue_dilithium_mont_ntt_rv32 — Dilithium 8-layer NTT & Montgomery based & 3+3+2 layers merging & RV32IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 7,054 | 7,061 | -7 | -0.10 % |
| poly_basemul_init | 1,035 | 1,034 | +1 | +0.10 % |
| poly_basemul_acc | 1,933 | 1,933 | +0 | +0.00 % |
| poly_basemul_acc_end | 3,115 | 3,115 | +0 | +0.00 % |
| poly_basemul | 2,026 | 2,026 | +0 | +0.00 % |
| poly_reduce | 1,226 | 1,226 | +0 | +0.00 % |
| intt | 7,561 | 7,562 | -1 | -0.01 % |

#### speed_dualissue_dilithium_plant_ntt_rv64 — Dilithium 8-layer NTT & Plantard based & 4+4 layers merging & RV64IM

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 8,258 | 8,258 | +0 | +0.00 % |
| poly_basemul_init | 872 | 872 | +0 | +0.00 % |
| poly_basemul_acc | 1,384 | 1,384 | +0 | +0.00 % |
| poly_basemul_acc_end | 2,705 | 2,705 | +0 | +0.00 % |
| poly_basemul | 2,320 | 2,320 | +0 | +0.00 % |
| poly_reduce | 1,607 | 1,607 | +0 | +0.00 % |
| intt | 8,484 | 8,484 | +0 | +0.00 % |

#### speed_dualissue_dilithium_mont_ntt_rvv — Dilithium 8-layer NTT & Montgomery based & 3+3+2 layers merging & RVV with VLEN128

| Function | Old [cycles] | New [cycles] | Δ cycles | Rel. speedup |
|---|---:|---:|---:|---:|
| ntt | 3,329 | 3,331 | -2 | -0.06 % |
| intt | 3,491 | 3,492 | -1 | -0.03 % |
| poly_basemul | 666 | 662 | +4 | +0.60 % |
| poly_basemul_acc | 815 | 815 | +0 | +0.00 % |
| ntt2normal_order | 1,040 | 1,042 | -2 | -0.19 % |
| normal2ntt_order | 1,040 | 1,042 | -2 | -0.19 % |
| poly_reduce | 536 | 537 | -1 | -0.19 % |
