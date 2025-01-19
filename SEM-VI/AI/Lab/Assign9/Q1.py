import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.probability import FreqDist

nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')


text = "This is a sample text for our text analysis tool."
tokens = word_tokenize(text)
print("\nTokenising -\n", tokens)
stop_words = set(stopwords.words('english'))
filtered_tokens = [token for token in tokens if token.lower() not in stop_words]
print("\nToken Filtering -\n", filtered_tokens)

stemmer = PorterStemmer()
lemmatizer = WordNetLemmatizer()

stemmed_tokens = [stemmer.stem(token) for token in filtered_tokens]
lemmatized_tokens = [lemmatizer.lemmatize(token) for token in filtered_tokens]

print("\nStemmed tokens:\n", stemmed_tokens)
print("\nLemmatized tokens:\n", lemmatized_tokens)

freq_dist = FreqDist(lemmatized_tokens)
print(freq_dist.most_common())