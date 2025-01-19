echo "  --- Key Generation"
openssl ecparam -genkey -name prime256v1 -out ecc_private_key.pem
openssl ec -in ecc_private_key.pem -pubout -out ecc_public_key.pem
echo "  --- Encryption"
echo "     ######"
echo " •• Generating Session Keys"
openssl rand -out session_key.bin 32

echo " •• Encrypting Session Keys"
openssl pkeyutl -encrypt -pubin -inkey ecc_public_key.pem -in session_key.bin -out encrypted_session_key.bin
echo "  --- Data Encryption"
openssl enc -aes-256-cbc -salt -in plaintext.txt -out encrypted_data.enc -pass file:session_key.bin
echo "     ######"
echo "  --- Decryption"
echo " -- Session Key Decryption"
openssl pkeyutl -decrypt -inkey ecc_private_key.pem -in encrypted_session_key.bin -out decrypted_session_key.bin
echo " -- Data Decryption"
openssl enc -d -aes-256-cbc -in encrypted_data.enc -out decrypted_data.txt -pass file:decrypted_session_key.bin



