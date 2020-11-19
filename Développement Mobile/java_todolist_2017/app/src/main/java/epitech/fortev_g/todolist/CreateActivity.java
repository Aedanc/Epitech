package epitech.fortev_g.todolist;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.Calendar;

public class CreateActivity extends AppCompatActivity {

    Button btnDatePicker, btnTimePicker;
    TextView txtDate, txtTime;
    SQLiteHelper database;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create);
        database = new SQLiteHelper(this);
        btnDatePicker=(Button)findViewById(R.id.btn_date);
        btnTimePicker=(Button)findViewById(R.id.btn_time);
        txtDate=(TextView)findViewById(R.id.in_date);
        txtTime=(TextView)findViewById(R.id.in_time);
    }

    public void onClickDate(View v) {


            // Get Current Date
            final Calendar c = Calendar.getInstance();
        int mYear = c.get(Calendar.YEAR);
        int mMonth = c.get(Calendar.MONTH);
        int mDay = c.get(Calendar.DAY_OF_MONTH);


            DatePickerDialog datePickerDialog = new DatePickerDialog(this,
                    new DatePickerDialog.OnDateSetListener() {

                        @Override
                        public void onDateSet(DatePicker view, int year,
                                              int monthOfYear, int dayOfMonth) {

                            txtDate.setText(dayOfMonth + "-" + (monthOfYear + 1) + "-" + year);

                        }
                    }, mYear, mMonth, mDay);
            datePickerDialog.show();
        }

    public void onClickTime(View v) {
        // Get Current Time
        final Calendar c = Calendar.getInstance();
        int mHour = c.get(Calendar.HOUR_OF_DAY);
        int mMinute = c.get(Calendar.MINUTE);

        // Launch Time Picker Dialog
        TimePickerDialog timePickerDialog = new TimePickerDialog(this,
                new TimePickerDialog.OnTimeSetListener() {

                    @Override
                    public void onTimeSet(TimePicker view, int hourOfDay,
                                          int minute) {

                        txtTime.setText(hourOfDay + ":" + minute);
                    }
                }, mHour, mMinute, true);
        timePickerDialog.show();
    }


    public void saveNewToDo(View v)
    {
        EditText title = findViewById(R.id.titleTodo);
        EditText content = findViewById(R.id.content);
        TextView time = findViewById(R.id.in_time);
        TextView date = findViewById(R.id.in_date);

        String data_title = title.getText().toString();
        String data_content = content.getText().toString();
        String data_time = time.getText().toString();
        String data_date = date.getText().toString();

        if (data_content.length() == 0 || data_title.length() == 0)
        {
            Toast.makeText(this, "You need at least a title and a content", Toast.LENGTH_SHORT).show();
            return;
        }
        if (database.addData(data_title, data_content, data_date, data_time))
        {
            Toast.makeText(this, "New Todo save!", Toast.LENGTH_SHORT).show();
            finish();
        }
        else
            Toast.makeText(this, "Sorry something goes wrong, try again", Toast.LENGTH_SHORT).show();
    }
}
