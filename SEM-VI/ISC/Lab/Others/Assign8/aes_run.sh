echo " --- AES Encryption..."
openssl enc -aes-256-cbc -salt -in plaintext.txt -out aes_cipher.enc -k 4dc997ceb26c7df47080353bb4256480e2570db62834b1950e1e4ddcf2ec4a45
echo "Cipher text generated.."
echo " --- Decryption.."
openssl enc -d -aes-256-cbc -in aes_cipher.enc -out aes_decrypted.txt -k 4dc997ceb26c7df47080353bb4256480e2570db62834b1950e1e4ddcf2ec4a45
echo "Decrypted Message Generated"
