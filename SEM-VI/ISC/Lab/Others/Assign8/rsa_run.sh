echo "  --- Generating Keys"
openssl genrsa -out rsaprivate.key 512
openssl rsa -in rsaprivate.key -pubout -out rsapublic.key
echo "  --- RSA Encryption"
openssl pkeyutl -encrypt -inkey rsapublic.key -pubin -in plaintext2.txt -out rsa_cipher.enc
echo "Message Encrypted"
echo "  --- RSA Decryption"
openssl pkeyutl -decrypt -inkey rsaprivate.key -in rsa_cipher.enc -out rsa.dec
echo "Message Decrypted"
